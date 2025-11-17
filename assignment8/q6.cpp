#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> h;
public:
    void push(int x) {
        h.push_back(x);
        int i = h.size() - 1;
        while (i > 0 && h[(i-1)/2] < h[i]) {
            swap(h[i], h[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void pop() {
        if (h.empty()) return;
        h[0] = h.back();
        h.pop_back();
        int n = h.size(), i = 0;
        while (true) {
            int l = 2*i+1, r = 2*i+2, mx = i;
            if (l < n && h[l] > h[mx]) mx = l;
            if (r < n && h[r] > h[mx]) mx = r;
            if (mx == i) break;
            swap(h[i], h[mx]);
            i = mx;
        }
    }

    int top() {
        return h.empty() ? -1 : h[0];
    }

    bool empty() {
        return h.empty();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(1);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
