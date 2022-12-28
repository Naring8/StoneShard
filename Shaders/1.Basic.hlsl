struct VertexInput
{
    float4 position : POSITION0; //시멘틱 용도
    float4 color : COLOR0;
};

// PI
struct PixelInput
{
    float4 position : SV_POSITION; //화면좌표계 포지션
    float4 color : COLOR0;
};

//오브젝트의 크기 회전 이동
cbuffer VS_WVP : register(b0) //register(b0)
{
    matrix WVP;
}
cbuffer VS_COLOR : register(b1)
{
    //4 개의 4바이트
    float4 color;
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

PixelInput VS(VertexInput input)
{
    //공간변환이 있을 예정인 곳
    PixelInput output; 
    output.position = mul(input.position, WVP);	
    output.color = input.color + (color * 2.0f - 1.0f);
    saturate(output.color);
    
    return output;
}
//->pixel  PS   ->color
//픽셀쉐이더 진입 함수
float4 PS(PixelInput input) : SV_TARGET //SV_TARGET 은 타겟이될 색깔 
{
	//if (input.position.y > 200.0f)
	//{
	//	return float4(1, 0, 0, 1);
	//}
    
	float4 outputColor;
	outputColor = saturate(input.color);
    
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
			outputColor.rgb += (inColor.rgb * 2.0f - 1.0f);
				
		}
		else
		{
			outputColor.rgb += (outColor.rgb * 2.0f - 1.0f);
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
			outputColor.rgb += (inColor.rgb * 2.0f - 1.0f);
			outputColor.rgb *= saturate(sum);
		}
		else
		{
			outputColor.rgb += (outColor.rgb * 2.0f - 1.0f);
		}
	}
    
	outputColor = saturate(outputColor);
    
	return outputColor;
	}