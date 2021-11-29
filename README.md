# AlgorithmTheory 《算法理论》presentation练习

### problem1-预测学生排名
- 用一个标记数组Bool[6]标记每个老师的说法，对的就是1，不对就是0
- 满足的条件就是，每个老师的标记值和为1；四个学生的排名互不一样

### problem2-凸多边形找坐标值最大点
- 对于横坐标x，可以用二分法，因为x先增大后减小；
- 对于纵坐标y，不可以使用二分法，先找到x最大的点，从该点开始往后找到y极大点，再与x最大的点的y进行比较

### problem3-合并排序
- 两个数组的一次比较大小，用index1和index2分别标记已经排到两个数组的什么位置。
- 可以从左到右，可以从右到左。
- 如果要从左到右开始的话，就要另外再定义一个数组进行存储，否则nums1的数值会丢失；
- 从右到左开始的话，可以直接将数字存在nums1的里面就可以了。

### problem4-找出假币
- 需要注意的是，找假币是找它的位置，不单单是找它的重量，所以排序之后对比首尾是不可取的。
- 减治法，将规模缩小，有些类似二分法，但又不完全一样。
- 有个找规律的想法在里面，时间复杂度O(log2 n)

### problem5-计数
- 遍历：一个个判断是否等于n，然后count计数
- 本质上在输入数组的时候直接定义一个计数数组的原理其实也是遍历，时间复杂度都是O(n)
- 二分法找数字出现的位置和结束的位置，两个位置序号相减，时间复杂度是O(log2 n)

### problem6-找出两个数和为特定值

- 时间复杂度O(n)

- 若只是简单的遍历，时间复杂度为O(n^2)，这样没有充分利用已经排好序的条件，不可取；

- 定义两个指针p和q，分别指向头和尾，比较这两数之和与给定数的大小关系，直到找到符合条件的一对数字，若p>q，则说明没有找到。

### problem7-DFS找指定路径和路径

### problem8-构建平衡二叉树

### problem9-跳台阶问题

- 递归求解，用F(n)表示第n个台阶的跳法总数

- 第一个台阶：一种可能性，F(1)=1

- 第二个台阶：两种可能性，F(2)=2

- 对于第n个台阶而言，它有可能是第n-1个台阶跳一步来的，也可能是第n-2个台阶跳两步来的，所以F(n)=F(n-1)+ F(n-2)

- 时间复杂度O(2^n)

- 还可以用动态规划、斐波拉契数列（迭代）做

### problem10-合并排序

- 跟problem3重复

### problem11-
