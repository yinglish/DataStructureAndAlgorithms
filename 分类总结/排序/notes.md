排序算法总结：将在不同的书籍等资料中的各种排序算法总结至此，每种算法选择一个版本的写法熟记

* 算法总结

稳定的排序      |     时间复杂度      |      空间复杂度
-----------|-------------|-------------
冒泡排序| 最差，平均都是O(n2)；最好是O(n)| 1
插入排序|同上|1
归并排序|所有情况都是O(nlgn)|O(n)
桶排序|O(n)|O(k)
基数排序|O(dn)|O(n)
二叉树排序|O(nlgn)|O(n)
图书馆排序|O(nlgn)|(1+epsilon)n

不稳定的排序|时间复杂度|空间复杂度
-----|----|----
选择排序|最差、平均都是O(n2)|1
希尔排序|O(nlgn)|1
堆排序|O(nlgn)|O(lgn)
快速排序|平均O(nlgn)、最坏O(n2)|1

* 排序的分类
  * 按数据是否设计内外存交换分
    * 内部排序
    * 外部排序
  * 按策略分内部排序方法
    * 插入排序
    * 选择排序
    * 交换排序
    * 归并排序
    * 分配排序

* 快速排序：

伪代码：
```C++
void QuickSort(SeqLst R, int low, int high)
{
    int pivot_pos; // 记录主元的位置
    if (low < high) // 仅区间长度大于1时才plxu
    {
        pivot_pos = Partition(R, low, high);
        QuickSort(R, low, pivot_pos - 1);
        QuickSort(R, pivot_pos + 1, high)
    }
}
```