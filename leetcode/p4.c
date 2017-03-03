/**
 * 2016-04-23
 * 经过一夜的思考，最后还是在网上找到了关键的信息：
 *
 * 如果我们去掉数组比中位数小的k个数，再去掉比中位数大的k个数，得到的子数组的中位数和原来的中位
 * 数相同。
 *
 * 也就是说，为了让去掉两边的数之后，中位数保持不变，必须每次去除的时候，两边去掉的数一样多。
 *
 * 最后的结果是音音酱写出来的。我还没理解。
 */
#include<stdio.h>

int min(int a, int b) {
    return a > b ? b : a;
}

void print(int* a, size_t s) {
    printf("[");
    for(int i = 0; i < s; i ++) {
        printf("%d ", a[i]);
    }
    printf("] L=%u\n", s);
}

double median(int* v1, int l1, int* v2, int l2, int n_lt_median) {
    print(v1, l1);
    print(v2, l2);

	if (l1 > l2)
		return median(v2, l2, v1, l1, n_lt_median);
	if (l1 == 0)
		return v2[n_lt_median - 1];
	if (n_lt_median == 1)
		return min(v1[0], v2[0]);

	int k1 = min(n_lt_median / 2, l1), k2 = n_lt_median - k1;
    printf("k1=%d, k2=%d, n_lt_median=%d\n\n", k1, k2, n_lt_median);

	if (v1[k1 - 1] < v2[k2 - 1]) {
		return median(v1 + k1, l1 - k1, v2, l2, n_lt_median - k1);
    } else if (v1[k1 - 1] > v2[k2 - 1]) {
		return median(v1, l1, v2 + k2, l2 - k2, n_lt_median - k2);
    } else {
		return v1[k1 - 1];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int k = (nums1Size + nums2Size) / 2;

    if ((nums1Size + nums2Size) % 2 == 0) {
        return (median(nums1, nums1Size, nums2, nums2Size, k) + median(nums1, nums1Size, nums2, nums2Size, k+1)) / 2.0;
    } else {
        return median(nums1, nums1Size, nums2, nums2Size, k+1);
    }
}

int main(int argc, char* argv[]) {
    int a1[] = { 1, 2, 6 };
    int a2[] = { 3, 4, 5 };
    printf("Result: %.3f", findMedianSortedArrays(a1, sizeof(a1)/sizeof(a1[0]), a2, sizeof(a2)/sizeof(a2[0])));

    return 0;
}
