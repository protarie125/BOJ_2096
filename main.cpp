#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto mxlist = vl(3);
	auto mnlist = vl(3);

	ll a, b, c;
	cin >> a >> b >> c;

	mxlist[0] = a;
	mxlist[1] = b;
	mxlist[2] = c;

	mnlist[0] = a;
	mnlist[1] = b;
	mnlist[2] = c;

	for (auto i = 1; i < n; ++i) {
		cin >> a >> b >> c;

		const auto& mx0 = max(mxlist[0], mxlist[1]) + a;
		const auto& mx1 = *max_element(mxlist.begin(), mxlist.end()) + b;
		const auto& mx2 = max(mxlist[1], mxlist[2]) + c;
		mxlist[0] = mx0;
		mxlist[1] = mx1;
		mxlist[2] = mx2;

		const auto& mn0 = min(mnlist[0], mnlist[1]) + a;
		const auto& mn1 = *min_element(mnlist.begin(), mnlist.end()) + b;
		const auto& mn2 = min(mnlist[1], mnlist[2]) + c;
		mnlist[0] = mn0;
		mnlist[1] = mn1;
		mnlist[2] = mn2;
	}

	cout << *max_element(mxlist.begin(), mxlist.end()) << ' '
		<< *min_element(mnlist.begin(), mnlist.end());

	return 0;
}