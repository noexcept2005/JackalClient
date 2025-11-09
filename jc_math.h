#pragma once
//数学库
#define sqrt2	1.4142135623730951
#define fequ(f1, f2) (abs(f1-f2) < 0.001f)

struct Point
{
	double x{ 0.0 };
	double y{ 0.0 };
};
struct Point3D
{
	double x{ 0.0 };
	double y{ 0.0 };
	double h{ 0.0 };
};

float AssessValueSmallStep(float x)
{
	x = abs(x);
	return x * 0.1f;
}

template<typename T>
inline T safe_divide(T numerator, T denominator, T fallback = 0)
{
	return (denominator == 0) ? fallback : numerator / denominator;
}



template <typename _T>
constexpr _T CJZAPI pow2(const _T& x)
{
	return (x * x);
}

RECT CJZAPI MakeRect(double left, double top, double right, double bottom)
{
	RECT rt;
	rt.left = LONG(left);
	rt.top = LONG(top);
	rt.right = LONG(right);
	rt.bottom = LONG(bottom);
	return rt;
}

// 计算逆时针旋转后的点坐标
Point RotatedPoint(double x, double y, double theta)
{
	double newX = x * cos(theta) + y * sin(theta);
	double newY = -x * sin(theta) - y * cos(theta);
	return { newX, newY };
}
//
//// 计算逆时针旋转后的矩形四个顶点坐标
//tuple<Point, Point, Point, Point> RotatedRectangle(double ox, double oy, double w, double h, double theta)
//{
//	// 计算矩形四个顶点相对于中心点的坐标
//	double halfWidth = w / 2.0;
//	double halfHeight = h / 2.0;
//
//	// 计算旋转后的四个顶点坐标
//	Point topLeft = RotatedPoint(-halfWidth, halfHeight, theta);
//	Point topRight = RotatedPoint(halfWidth, halfHeight, theta);
//	Point bottomLeft = RotatedPoint(-halfWidth, -halfHeight, theta);
//	Point bottomRight = RotatedPoint(halfWidth, -halfHeight, theta);
//
//	topLeft.x += ox;
//	topLeft.y += oy;
//	topRight.x += ox;
//	topRight.y += oy;
//	bottomLeft.x += ox;
//	bottomLeft.y += oy;
//	bottomRight.x += ox;
//	bottomRight.y += oy;
//
//	return make_tuple(topLeft, topRight, bottomLeft, bottomRight);
//}

template <typename _T>
constexpr _T CJZAPI ClampA(_T& val, _T min = 0, _T max = 2147483647) {	//限定范围
	if (val < min) val = min;
	else if (val > max) val = max;
	return val;
}
template <typename _T>
constexpr _T CJZAPI Clamp(_T val, _T min = 0, _T max = 2147483647) {	//限定范围
	if (val < min) val = min;
	else if (val > max) val = max;
	return val;
}
constexpr int CJZAPI ClampByte(int b)
{
	return Clamp(b, 0, 255);
}
template <typename _T>
auto CJZAPI MapValue(_T val, _T prev_min, _T prev_max, _T cur_min, _T cur_max)
{
	return cur_min + (cur_max - cur_min) * (val - prev_min) / double(prev_max - prev_min);
}
template <typename _T>
void CJZAPI MapValueA(_T& val, _T prev_min, _T prev_max, _T cur_min, _T cur_max)
{
	val = cur_min + (cur_max - cur_min) * (val - prev_min) / double(prev_max - prev_min);
}
// 模板函数：计算正弦值并将其映射到指定范围
template <typename T>
auto SinValue(T minValue, T maxValue, clock_t periodTime = 2000L, float phase0 = 0.0f) {
	// 获取当前时间
	clock_t currentTime = clock();

	// 计算周期内的时间
	double normalizedTime = static_cast<double>(currentTime % periodTime) / periodTime;

	// 应用相位，计算正弦值并将其映射到[0, 1]
	double sinValue = 0.5 * (1.0 + sin(2.0 * PI * (normalizedTime + phase0)));

	// 将正弦值映射到[minValue, maxValue]
	return minValue + static_cast<T>((maxValue - minValue) * sinValue);
}

// 返回三角脉冲函数在特定时刻 t 的值
double TriangularPulse(double t, double period, double Amp = 1.0)
{
	// 将 t 限制在一个周期内
	t = fmod(t, period);

	// 计算三角脉冲函数的值
	if (t < period / 2.0)
		return t / (period / 2.0) * Amp;
	else
		return (1.0 - (t - period / 2.0) / (period / 2.0)) * Amp;
}
template <typename _T>
constexpr double CJZAPI Lerp(_T startValue, _T endValue, double rate)
{
	if (fequ(rate, 0.0))
		return startValue;
	if (fequ(rate, 1.0))
		return endValue;
	return startValue + (endValue - startValue) * rate;
}
template <typename _T>
constexpr double CJZAPI LerpRadian(_T startAngle, _T endAngle, double rate)
{
	while (endAngle - startAngle > PI + 0.1)
		endAngle -= PI * 2.0;
	while (endAngle - startAngle < -PI - 0.1)
		endAngle += PI * 2.0;
	return Lerp(startAngle, endAngle, rate);
}
//template <typename _T>
//constexpr double CJZAPI DestRadian(_T dstOriginal, _T startAngle)
//{
//	while (dstOriginal - startAngle > PI + 0.1)
//		dstOriginal -= PI * 2.0;
//	while (dstOriginal - startAngle < -PI - 0.1)
//		dstOriginal += PI * 2.0;
//	return dstOriginal;
//}
template <typename T>
constexpr double DestRadian(T dstOriginal, T startAngle) {
	constexpr double TwoPi = 2.0 * PI; // 定义2π的值

	// 计算起始角和终止角的差值
	double diff = dstOriginal - startAngle;

	// 将差值调整到范围 [-π, π]
	diff = fmod(diff + PI, TwoPi) - PI;

	// 计算处理后的终止角
	double result = startAngle + diff;

	return result;
}
inline double CJZAPI EaseInExpo(double _x)
{
	return fequ(_x, 0.0f) ? 0.0 : pow(2.0, 10.0 * _x - 10.0);
}
inline double EaseInOutSine(double _x)
{	//retval,_x ∈ [0,1]
	return -(cos(PI * _x) - 1) / 2;
}
inline double EaseInOutBack(double _x)
{
	const double c1 = 1.70158;
	const double c2 = c1 * 1.525;
	return _x < 0.5
		? (pow(2 * _x, 2) * ((c2 + 1) * 2 * _x - c2)) / 2
		: (pow(2 * _x - 2, 2) * ((c2 + 1) * (_x * 2 - 2) + c2) + 2) / 2;
}
inline double CJZAPI EaseOutCubic(double _x)
{
	return 1 - pow(1 - _x, 3);
}

inline double CJZAPI EaseOutBack(double x) {
	constexpr double c1 = 1.70158;
	constexpr double c3 = c1 + 1;

	return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
}
inline double EaseInOutElastic(double _x)
{
	const double c5 = (2 * PI) / 4.5;
	return fequ(_x, 0.0)
		? 0.0
		: fequ(_x, 1.0)
		? 1.0
		: _x < 0.5
		? -(pow(2, 20 * _x - 10) * sin((20 * _x - 11.125) * c5)) / 2
		: (pow(2, -20 * _x + 10) * sin((20 * _x - 11.125) * c5)) / 2 + 1;
}
inline double CJZAPI EaseOutBounce(double _x)
{
	const double n1 = 7.5625;
	const double d1 = 2.75;

	if (_x < 1 / d1) {
		return n1 * _x * _x;
	}
	else if (_x < 2 / d1) {
		return n1 * (_x -= 1.5 / d1) * _x + 0.75;
	}
	else if (_x < 2.5 / d1) {
		return n1 * (_x -= 2.25 / d1) * _x + 0.9375;
	}
	else {
		return n1 * (_x -= 2.625 / d1) * _x + 0.984375;
	}
}
inline double CJZAPI EaseInQuad(double _x)
{
	return _x * _x;
}
inline double EaseInOutBounce(double _x)
{
	return _x < 0.5
		? (1 - EaseOutBounce(1 - 2 * _x)) / 2
		: (1 + EaseOutBounce(2 * _x - 1)) / 2;
}
inline double EaseInOutExpo(double _x)
{
	return fequ(_x, 0.0)
		? 0.0
		: fequ(_x, 1.0)
		? 1.0
		: _x < 0.5 ? pow(2, 20 * _x - 10) / 2
		: (2 - pow(2, -20 * _x + 10)) / 2;
}

long CJZAPI RandomRange(auto Min = 0, auto Max = 32767, bool rchMin = true, bool rchMax = true) {
	//随机数值区间
	if (Max - Min == 0)
		return Min;

	//a = random(Max);
	//long a = rand();

	static random_device rd;  // 硬件熵源
	static mt19937 gen(rd()); // 梅森旋转引擎

	// 处理不同的区间类型
	if (rchMin && rchMax) {     // [Min, Max]
		uniform_int_distribution<long> dist(Min, Max);
		return dist(gen);
	}
	else if (rchMin && !rchMax) { // [Min, Max)
		uniform_int_distribution<long> dist(Min, Max - 1);
		return dist(gen);
	}
	else if (!rchMin && rchMax) { // (Min, Max]
		uniform_int_distribution<long> dist(Min + 1, Max);
		return dist(gen);
	}
	else {                        // (Min, Max)
		uniform_int_distribution<long> dist(Min + 1, Max - 1);
		return dist(gen);
	}


	//g_debug_string = "rr=" + str(a);
	//g_lastDebugStr = clock();

	//if (rchMin && rchMax)	//[a,b]
	//	return (a % (Max - Min + 1)) + Min;
	//else if (rchMin && !rchMax)		//[a,b)
	//	return (a % (Max - Min)) + Min;
	//else if (!rchMin && rchMax)		//(a,b]
	//	return (a % (Max - Min)) + Min + 1;
	//else							//(a,b)
	//	return (a % (Max - Min - 1)) + Min + 1;
}
double CJZAPI RandomRangeDouble(double _min, double _max,	//min,max
	bool rchMin = true, bool rchMax = true,	//开/闭 
	UINT uPrec = 2	//精度（位数） 
)
{	//随机小数区间 
	double p_small = pow(10.0f, -int(uPrec));
	int p_big = (int)pow(10, uPrec);
	int l = int(p_big * _min);
	int r = int(p_big * _max);
	int res;
	res = RandomRange(l, r, rchMin, rchMax);
	return (p_small * (double)res);
}
template<typename _T>
inline _T CJZAPI Choice(initializer_list<_T> choices) {
	vector<_T> vec(choices);
	return vec[RandomRange(0, vec.size() - 1, true, true)];
}
template<typename _T>
inline _T CJZAPI Choice(const vector<_T>& choices_vector) {
	return choices_vector[RandomRange(0, choices_vector.size() - 1, true, true)];
}
template<typename _T>
inline _T& CJZAPI ChoiceRef(vector<_T>& choices_vector) {
	return choices_vector[RandomRange(0, choices_vector.size() - 1, true, true)];
}

template <typename _T>
void CJZAPI random_shuffle(vector<_T>& vec) {
	random_device rd;
	mt19937 g(rd());

	shuffle(vec.begin(), vec.end(), g);
}

template<typename _T>
inline bool CJZAPI Percent(_T prob) {
	return (RandomRange(0, 100, true, false) < prob);
}
template<typename _T>
inline bool CJZAPI Permille(_T prob) {	//千分数
	return (RandomRange(0, 1000, true, false) < prob);
}
inline bool CJZAPI Decision(float prob)
{
	return Percent(prob * 100.0f);
}
inline bool CJZAPI FractionProb(auto denominator, int numerator = 1)
{
	return Percent(100.0 * numerator / double(denominator));
}

void GenerateShakeOffset(int& offset_x, int& offset_y)
{
	offset_x = RandomRange(-10, 10);
	offset_y = RandomRange(-10, 10);
}

// 函数：生成正态分布随机数
double GenerateNormalRandom(double mean, double stddev)
{
	random_device rd; // 使用随机设备作为种子
	mt19937 gen(rd()); // 使用 Mersenne Twister 引擎
	normal_distribution<double> dist(mean, stddev); // 创建正态分布对象

	return Clamp(dist(gen), 0.0, 1000000.0); // 生成并返回随机数
}


typedef USHORT DIR, * PDIR;	//方向
#define DIR2	DIR
#define DIR4	DIR
#define DIR8	DIR
#define PDIR2	PDIR
#define PDIR4	PDIR
#define PDIR8	PDIR

#define NO_DIR 0x00
#define UP 0x01
#define DIR_FIRST UP
#define RIGHTUP 0x02
#define RIGHT 0x03
#define RIGHTDOWN 0x04
#define DOWN 0x05
#define LEFTDOWN 0x06
#define LEFT 0x07
#define LEFTUP 0x08
#define DIR_LAST LEFTUP

#define VERT	0x01
#define HORIZ	0x03


const vector<string> dir_names
{
	"none", "up", "rightup", "right", "rightdown", "down", "leftdown", "left", "leftup",
};
DIR ParseDir(const string& s)
{
	for (DIR dir = 0; dir <= DIR_LAST; ++dir)
		if (s == dir_names.at(dir))
			return dir;
	//ErrorLogTip(nullptr, "Invalid direction name: " + s, "ParseDir");
	return 0;
}
inline string GetDirName(DIR dir)
{
	return dir_names.at(dir);
}

inline DIR OppoDir(DIR dir)
{
	return (dir + 4) % 8;
}

void DirOffsetPos(double& x, double& y, DIR dir, double offset = 10.0) {
	//依据方向位移坐标

	if (dir == UP)
		y -= offset;
	else if (dir == RIGHTUP)
		x += offset, y -= offset;
	else if (dir == RIGHT)
		x += offset;
	else if (dir == RIGHTDOWN)
		x += offset, y += offset;
	else if (dir == DOWN)
		y += offset;
	else if (dir == LEFTDOWN)
		x -= offset, y += offset;
	else if (dir == LEFT)
		x -= offset;
	else if (dir == LEFTUP)
		x -= offset, y--;
	else {
		return;
	}
}

DIR RandomDir(void)
{
	return DIR(RandomRange(0, 7, true, true));
}

double StdRadian(double rad) {
	constexpr double TwoPi = 2.0 * PI; // 定义2π的值

	// 将弧度值调整到范围 [0, 2π]
	rad = fmod(rad, TwoPi);
	if (rad < 0.0) {
		rad += TwoPi;
	}

	return rad;
}
inline double OppoRadian(double rad)
{
	return StdRadian(rad + PI);
}
double GetDirRadianForDraw(DIR dir)
{	//获取方向弧度rad
	switch (dir)
	{
	case UP: {
		return 0;
		break;
	}
	case LEFTUP: {
		return (PI / 4);
		break;
	}
	case LEFT: {
		return PI / 2;
		break;
	}
	case LEFTDOWN: {
		return (PI / 4 * 3);
		break;
	}
	case DOWN: {
		return PI;
		break;
	}
	case RIGHTDOWN: {
		return (PI * 1.25);
		break;
	}
	case RIGHT: {
		return (PI * 1.5);
		break;
	}
	case RIGHTUP: {
		return (PI * 1.75);
		break;
	}
	default: {
		//ErrorLogTip(NULL, "Invalid direction", "GetDirRadianForDraw");
		return 0;
		break;
	}
	}
}
inline double GetDirRadian(DIR dir)
{
	return StdRadian(GetDirRadianForDraw(dir) + PI / 2.0);
}
double RadianDiff(double rad_1, double rad_2)
{
	double diff = abs(StdRadian(rad_1) - StdRadian(rad_2));
	if (diff > PI)
		diff = 2 * PI - diff;
	return diff;
}
bool LeftTheta(double radian)
{
	double stdrad = StdRadian(radian);
	return (stdrad > PI / 2.0 && stdrad < PI * 1.5);
}
bool RightTheta(double radian)
{
	double stdrad = StdRadian(radian);
	return (stdrad < PI / 2.0 || stdrad > PI * 1.5);
}
bool DownTheta(double radian)
{
	double stdrad = StdRadian(radian);
	return (stdrad > PI);
}
bool UpTheta(double radian)
{
	double stdrad = StdRadian(radian);
	return (stdrad < PI);
}
double RandomTheta()
{
	return RandomRangeDouble(0.0, PI * 2.0);
}

bool IsVertDir(DIR dir)
{
	if (dir == UP || dir == DOWN)
		return true;
	return false;
}
bool IsHorizDir(DIR dir)
{
	if (dir == RIGHT || dir == LEFT)
		return true;
	return false;
}
bool IsBentDir(DIR dir)
{
	if (dir >= RIGHTUP && dir <= LEFTUP)
		return true;
	return false;
}
inline double RadToDeg(double radian)
{
	return radian / PI * 180.0;
}
inline double DegToRad(double degrees)
{
	return degrees / 180.0 * PI;
}

bool InRect(const RECT& rt, int x, int y)
{
	if (x >= rt.left && x <= rt.right
		&& y <= rt.bottom && y >= rt.top)
		return true;
	return false;
}
double Distance(double x1, double y1, double x2, double y2)
{	//求两点距离
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
double Distance(double x1, double y1, double h1, double x2, double y2, double h2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(h1 - h2, 2));
}
bool InDistance(double x0, double y0, double x, double y, double dist)
{	//距离内？
	double fdist = Distance(x0, y0, x, y);
	return (fdist < dist);
}
inline bool OnComplexPlane(double x, double y)
{	//是否在复平面上
	return x != x || y != y;
}
//
//// 生成服从标准正态分布的随机数（均值为0，方差为1）
//double GenerateStandardNormalRandom() {
//	static bool hasSpare = false;
//	static double spare;
//
//	if (hasSpare) {
//		hasSpare = false;
//		return spare;
//	}
//
//	hasSpare = true;
//
//	double u, v, s;
//	do {
//		u = (rand() / ((double)RAND_MAX)) * 2.0 - 1.0;
//		v = (rand() / ((double)RAND_MAX)) * 2.0 - 1.0;
//		s = u * u + v * v;
//	} while (s >= 1.0 || s == 0.0);
//
//	s = sqrt(-2.0 * log(s) / s);
//	spare = v * s;
//	return u * s;
//}
//
//// 生成服从均值mean，方差variance的正态分布随机数
//double GenerateNormalRandom(double mean, double variance) {
//	// 生成标准正态分布随机数
//	double standardNormal = GenerateStandardNormalRandom();
//	// 将标准正态分布转换为目标分布
//	return mean + sqrt(variance) * standardNormal;
//}