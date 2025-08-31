struct VS_INPUT
{
    float4 position : POSITION;   // CreateInputLayout()에서 사용했던 POSITION
   // float4 color : COLOR;         // CreateInputLayout()에서 사용했던 COLOR
    float2 uv : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 position : SV_POSITION;
    //float4 color : COLOR;
    float2 uv : TEXCOORD;
};

// IA - VS - RS - PS - OM
VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output;
    output.position = input.position;
    output.uv = input.uv;
    
    return output;
}

Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);
 
float4 PS(VS_OUTPUT input) : SV_Target
{ 
    // Sample함수를 활용 input.uv 값에 따라서 색상을 추출.
    float4 color = texture0.Sample(sampler0, input.uv);
    
    return color;
}