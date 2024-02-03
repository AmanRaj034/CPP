//https://codeforces.com/blog/entry/125435

#define debug(...) cout << __LINE__ << ": [", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(arr, n) cout << __LINE__ << ": [", _DEBUG_UTIL_::printerArr(#arr, arr, n)
namespace _DEBUG_UTIL_
{
using namespace std;
/* Primitive Datatypes Print */
void print(const char *x) {}
void print(bool x) { cout << (x ? "T" : "F"); }
void print(char x) { cout << '\'' << x << '\''; }
void print(signed short int x) { cout << x; }
void print(unsigned short int x) { cout << x; }
void print(signed int x) { cout << x; }
void print(unsigned int x) { cout << x; }
void print(signed long int x) { cout << x; }
void print(unsigned long int x) { cout << x; }
void print(signed long long int x) { cout << x; }
void print(unsigned long long int x) { cout << x; }
void print(float x) { cout << x; }
void print(double x) { cout << x; }
void print(long double x) { cout << x; }
void print(string x) { cout << '\"' << x << '\"'; }
template <size_t N>
void print(bitset<N> x) { cout << x; }
void print(vector<bool> x)
{
	/* vector<bool> doesn't work in general iteration template because of rvalue problems */
	int f = 0;
	cout << '{';
	for (bool i : x)
	{
		cout << (f++ ? "," : "");
		cout << (i ? "T" : "F");
	}
	cout << "}";
}
/* Templates Declarations to support nested datatypes */
template <typename T>
void print(T x);
template <typename T>
void print(vector<vector<T>> mat);
template <typename T, size_t N>
void print(T (&arr)[N]);
template <typename T, size_t N, size_t M>
void print(T (&mat)[N][M]);
template <typename... T>
void print(tuple<T...> x);
template <typename F, typename S>
void print(pair<F, S> x);
template <typename T>
void print(priority_queue<T> pq);
template <typename T>
void print(priority_queue<T, vector<T>, greater<T>> pq);
template <typename T>
void print(stack<T> st);
template <typename T>
void print(queue<T> q);
/* Template Datatypes Definitions */
template <typename T>
void print(T x)
{
	/* This works for every container that supports range-based loop i.e. vector, set, map, dequeue */
	int f = 0;
	cout << '{';
	for (auto i : x)
		cout << (f++ ? "," : ""), print(i);
	cout << "}";
}
template <typename T>
void print(vector<vector<T>> mat)
{
	/* Specialized for 2D to format every 1D in new line */
	int f = 0;
	cout << "{\n";
	for (auto i : mat)
		cout << (f++ ? ",\n" : ""), print(i);
	cout << "}\n";
}
template <typename T, size_t N>
void print(T (&arr)[N])
{
	/* Helps in iterating through arrays and prevent decays */
	int f = 0;
	cout << '{';
	for (auto &i : arr)
		cout << (f++ ? "," : ""), print(i);
	cout << "}";
}
template <typename T, size_t N, size_t M>
void print(T (&mat)[N][M])
{
	/* Helps in iterating through 2D arrays and prevent decays and also print arrays in new line */
	int f = 0;
	cout << "{\n";
	for (auto &i : mat)
		cout << (f++ ? ",\n" : ""), print(i);
	cout << "}\n";
}
template <typename... T>
void print(tuple<T...> x)
{
	int f = 0;
	cout << '(';
	apply([&f](auto... args)
	{ ((cout << (f++ ? "," : ""), print(args)), ...); },
	x);
	cout << ')';
}
template <typename F, typename S>
void print(pair<F, S> x)
{
	/* Works for pairs and iterating through maps */
	cout << '(';
	print(x.first);
	cout << ',';
	print(x.second);
	cout << ')';
}
template <typename T>
void print(priority_queue<T> pq)
{
	int f = 0;
	cout << '{';
	while (!pq.empty())
		cout << (f++ ? "," : ""), print(pq.top()), pq.pop();
	cout << "}";
}
template <typename T>
void print(priority_queue<T, vector<T>, greater<T>> pq)
{
	int f = 0;
	cout << '{';
	while (!pq.empty())
		cout << (f++ ? "," : ""), print(pq.top()), pq.pop();
	cout << "}";
}
template <typename T>
void print(stack<T> st)
{
	int f = 0;
	cout << '{';
	while (!st.empty())
		cout << (f++ ? "," : ""), print(st.top()), st.pop();
	cout << "}";
}
template <typename T>
void print(queue<T> q)
{
	int f = 0;
	cout << '{';
	while (!q.empty())
		cout << (f++ ? "," : ""), print(q.front()), q.pop();
	cout << "}";
}
/* Printer functions responsible for.... printing beautifully ? */
template <typename T>
void printer(const char *name, T &&head)
{
	/* Base conditions for printer */
	cout << name << " = ";
	print(head);
	cout << "]\n";
}
template <typename T, typename... V>
void printer(const char *names, T &&head, V &&...tail)
{
	/* Using && to capture both lvalues and rvalues */
	int bracket = 0, i = 0;
	while (names[i] != ',' or bracket != 0)
	{
		if (names[i] == '(')
			bracket++;
		else if (names[i] == ')')
			bracket--;
		i++;
	}
	cout.write(names, i) << " = ";
	print(head);
	cout << " ||";
	printer(names + i + 1, tail...);
}
/* PrinterArr */
template <typename T>
void printerArr(const char *name, T arr[], int N)
{
	cout << name << " : {";
	for (int i = 0; i < N; i++)
	{
		cout << (i ? "," : ""), print(arr[i]);
	}
	cout << "}]\n";
}
}