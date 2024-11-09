float persistence = 0.50;
int Number_Of_Octaves = 6;
inline double Noise(int x,int y){
    int n = x + y * 57;  
    n = (n<<13) ^ n;
    return ( 1.0 - ( (n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
}
inline double SmoothedNoise(int x, int y){
    double corners = ( Noise(x-1, y-1)+Noise(x+1, y-1)+Noise(x-1, y+1)+Noise(x+1, y+1) ) / 16;
    double sides = ( Noise(x-1, y) +Noise(x+1, y) +Noise(x, y-1) +Noise(x, y+1) ) / 8;
    double center = Noise(x, y) / 4;
    return corners + sides + center;
}
inline double Cosine_Interpolate(double a,double b, double x){
    double ft = x * 3.1415927;
    double f = (1 - cos(ft)) * 0.5;
    return a*(1-f) + b*f;
}
inline double InterpolatedNoise(float x,float y){
    int integer_X = int(x);
    float  fractional_X = x - integer_X;
    int integer_Y = int(y);
    float fractional_Y = y - integer_Y;
    double v1 = SmoothedNoise(integer_X, integer_Y);
    double v2 = SmoothedNoise(integer_X + 1, integer_Y);
    double v3 = SmoothedNoise(integer_X, integer_Y + 1);
    double v4 = SmoothedNoise(integer_X + 1, integer_Y + 1);
    double i1 = Cosine_Interpolate(v1, v2, fractional_X);
    double i2 = Cosine_Interpolate(v3, v4, fractional_X);
    return Cosine_Interpolate(i1, i2, fractional_Y);
}
double rd;
double rd2;
inline double PerlinNoise(float x,float y)    // ���յ��ã�����(x,y)������Ӧ��PerlinNoiseֵ
{
	x+=rd;
	y+=rd2;
    double total = 0;
    double p = persistence;
    int n = Number_Of_Octaves;
    for(int i=0; i<n; ++i)
    {
        double frequency = pow(2,i);
        double amplitude = pow(p,i);
        total = total + InterpolatedNoise(x * frequency, y * frequency) * amplitude;
    }
 
    return total;
}
