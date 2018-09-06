# problems

## 1.Exercise  
  LongnumAdd：**字符串大整数相加**  
  divideapple：数学规律，移动苹果使每个人苹果数相同，满足每个人与平均数相差为偶数  
  likeword：**正则表达式匹配**，单词不包含：连续相等的字母、形如“xyxy”的子序列、全部为大写  
  luckybag：dfs，满足所有数字之和大于数字之积的子数组个数  
  mixcolor：数学问题+动态规划+贪心，颜色混合（A OR B），计算需要购买的颜料种类  
  phonenumber：数学规律，输出字符串对应的最小电话号码  
  plalindrome：数学问题，找变为回文序列的最小转换次数**（判断回文序列）**  
  StringToInteger：**string转int**合法判断，正负号转换  
  maxsubseq：**最长公共子序列**，个数以及子序列集合  
  BigNumMuti：**大数运算求高精度幂，float型数据求幂**  
  CountPrimes：计算小于n的素数个数，**数学**  
  bestsubstring：将字符串尽可能分割为多个部分，各子串不包含相同字符**暴力**

  
### dp/   
  chrous：相邻两学生为止编号差不超过d，k个学生能力值乘积最大  
  jumpstone：石板跳跃  
  LPartitionEqualSubsetSum：判断数组是否能分为和相等的两部分  
  mindis：**最小编辑距离**  

### leetcode/   
  435nooverlapintervals：不重叠区间个数，**贪心算法**，按区间开始时间排序，然后检查与上一个区间是否重叠，若重叠则删除结束时间大的区间  
  146LRUcache：实现LRU算法，**hash+双向链表**，双向链表用于存储数据结点，hash用于快速搜索  
  451sortbyfre：按照字母出现次数对字符串排序，**用priority_queue+map实现**  
  75sortcolor：三种颜色排序，**三向切分快排**，大于当前数（index表示开始），小于当前数（index表示末尾），等于当前数（index表示末尾）  
  
## 2.Wangyi  
  2-points：struct**重载运算符**  
  bagproblem：0-1背包（dfs）  
  magiccoin：数学规律，最后一步为2*x+1还是2*x+2  
  stringchip：输出格式，**四舍五入+小数点位数**  

## 3.HuaWei  
  bag：dfs，有容量的书包能装零食的最大价值  
  charconvert：大小写转化，getline  
  typedef：**字符串分割**判断typedef语句是否合法    

## 4.Toutiao
  2-1team：划分小组，**并查集，dfs**  
  2-2triword：找规律加动态规划，**只能通过10%**  
  2-3doubleword：判断字符串转换后是否相等，**暴力法超时**  
  2-4air：**周期数列的最长非递减子序列**  
## 5.Ali
  Bagua：矩阵数据求连通域，8邻域方向表示（4邻域方向表示）**dfs && bfs**  
  path：有向图求路径数最大的节点,有向图用邻接表表示**dfs**，dfs思路与矩阵不同，遍历时控制邻接表第一个index  
