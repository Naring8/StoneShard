struct VertexInput
{
    float4 position : POSITION0;
    float2 uv : UV0;
};
// PI
struct PixelInput
{
    float4 position : SV_POSITION; //ȭ����ǥ�� ������
    float2 uv : UV0; //���ε� ��ǥ
    float4 color : COLOR0; //��������
};

//������� ũ��� 16byte����� �������Ѵ�.

cbuffer VS_WVP : register(b0)
{
    matrix WVP;
}
cbuffer VS_COLOR : register(b1)
{
    //4 ���� 4����Ʈ
    float4 color;
}
cbuffer VS_UV : register(b2)
{
    float4 uv;
}

struct PointLight
{
	float2 screenPos;
	float radius;
	float padding;
};

cbuffer PS_LIGHT : register(b0)
{
	PointLight lights[10];
    float4 select;
    float4 outColor;
    float4 inColor;
};

//���ؽ� ���̴�
//��ȯ��  �Լ��̸�(�Ű�����)
// VertexInput(in) ->  VS  -> PixelInput (out)
PixelInput VS(VertexInput input)
{
    //������ȯ�� ���� ������ ��
    PixelInput output;
    //output.Position * input.Position;
    //L-W
    output.position = mul(input.position, WVP);
    
    output.color = color;
    
    //���ε� ��ǥ ���
    output.uv = input.uv;
    
    [branch]
    if (output.uv.x == 0.0f)
        output.uv.x = uv.x;
    else
        output.uv.x = uv.z;
    
    [branch]
    if (output.uv.y == 0.0f)
        output.uv.y = uv.y;
    else
        output.uv.y = uv.w;

    return output;
}

//�ؽ��� �ڿ�  (srv) ���� ����
Texture2D Texture : register(t0);

//�����
SamplerState Sampler : register(s0);

//�ȼ����̴� ���� �Լ�
float4 PS(PixelInput input) : SV_TARGET //SV_TARGET �� Ÿ���̵� ���� 
{
    float4 TextureColor =
    // ���ε� ��ǥ�� �ؽ��� �ε�
    Texture.Sample(Sampler, input.uv);
    
    //�о�� �׸������� �ȼ������� ���ǹ����� ��
    [flatten]
    if (TextureColor.r == 1.0f &&
        TextureColor.g == 0.0f &&
        TextureColor.b == 1.0f)
    {
        discard;
    }
    
    TextureColor = TextureColor + (input.color * 2.0f - 1.0f);
	TextureColor = saturate(TextureColor);
    
     //����
	if (select.x == 0.0f)
	{
		float temp = 0.0f;
        
		for (int i = 0; i < 10; i++)
		{
			float2 minus = input.position.xy - lights[i].screenPos;
			float dis = minus.x * minus.x + minus.y * minus.y;
			dis = sqrt(dis);
            
			temp += (dis < lights[i].radius);
		}
		if (temp)
		{
			TextureColor.rgb += (inColor.rgb * 2.0f - 1.0f);
				
		}
		else
		{
			TextureColor.rgb += (outColor.rgb * 2.0f - 1.0f);
		}
	}
	else
	{
		float sum = 0.0f;
        
		for (int i = 0; i < 10; i++)
		{
			float2 minus = input.position.xy - lights[i].screenPos;
			float dis = minus.x * minus.x + minus.y * minus.y;
			dis = sqrt(dis);
            
			float temp = 1.0f - saturate(dis / lights[i].radius);
			sum += temp;
		}
        
		if (sum)
		{
			TextureColor.rgb += (inColor.rgb * 2.0f - 1.0f);
			TextureColor.rgb *= saturate(sum);
		}
		else
		{
			TextureColor.rgb += (outColor.rgb * 2.0f - 1.0f);
		}
	}
    
	TextureColor = saturate(TextureColor);

    return TextureColor;
}