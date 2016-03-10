#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tape {
    unsigned long long value, amount;
};

typedef vector<Tape> Heap;
Heap heap;

bool sort_func(Tape a, Tape b) {
    return a.value < b.value;
}

long long find_max(long long p) {
    Tape t;
    for (long long i=p; i >= 0; i--) {
        t = heap[i];
        if (t.amount > 1) {
            return i;
        }
    }
    return -1;
}

long long insert_tape(Tape tape, long long pointer) {
    unsigned long long i;
    for (i = pointer; i < heap.size(); i++) {
        if (heap[i].value == tape.value) {
            heap[i].amount += tape.amount;
            return i;
        } else if (heap[i].value > tape.value) {
            heap.insert(heap.begin() + i, tape);
            return i;
        }
    }

    heap.push_back(tape);
    return i;
}

int main() {
    unsigned long long n, value, amount;
    long long pointer, p , new_p;
    Tape t, new_t;

    scanf("%llu",&n);
    pointer = n - 1;
    for (unsigned long long i=0; i<n; i++) {
        scanf("%llu %llu",&value, &amount);
        t.value = value;
        t.amount = amount;
        heap.push_back(t);
    }

    sort(heap.begin(), heap.end(), sort_func);

    while (pointer >= 0) {
        p = find_max(pointer);

        if (p >= 0) {
            t = heap[p];
            new_p = p;
            while (t.amount > 1) {
                new_t.amount = t.amount / 2;
                new_t.value = t.value * 2;

                if (t.amount % 2 == 0) {
                    heap.erase(heap.begin() + new_p);
                    if (new_p > 0) {
                        new_p--;
                    }
                } else {
                    heap[p].amount = 1;
                }

                new_p = insert_tape(new_t, new_p);
                t = heap[new_p];
            }
        }
        pointer = p - 1;
    }

    printf("%lu", heap.size());

    return 0;
}
