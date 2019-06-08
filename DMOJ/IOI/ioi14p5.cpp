#define max(a, b) (a > b ? a : b)

int q[100005];

int findSample(int n, int confidence[], int host[], int protocol[]) {
    for (int i = n - 1; i > 0; i--) {
        if (protocol[i] == 0)
            confidence[host[i]] += q[i], q[host[i]] = max(confidence[i] + q[host[i]], q[host[i]] + q[i]);
        else if (protocol[i] == 1)
            confidence[host[i]] = max(max(confidence[host[i]] + q[i], confidence[i] + q[host[i]]),
                                      confidence[host[i]] + confidence[i]), q[host[i]] += q[i];
        else
            confidence[host[i]] = max(confidence[host[i]] + q[i], confidence[i] + q[host[i]]), q[host[i]] += q[i];
    }
    return max(confidence[0], q[0]);
}