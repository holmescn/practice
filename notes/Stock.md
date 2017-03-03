% 龙虎榜分析
% 张鹏程
% 2015-12-11

# 龙虎榜 DataSet 准备

1. 获得 Summary 里的日期列表
2. 给定一个日期，获得一个 code 列表
3. 获得 name, stockId
4. 根据 date, stockId, 获得 ReasonCodeSet, SummaryIds
5. 根据 SummaryId, 获取 volume, proportion
6. 根据 SummaryId, 获取 traderId, buyAmount, sellAmount
7. 根据 traderId, 统计这个 trader 的 appearTimes 和 successRatio
8. 计算 buyAmount 和 sellAmount 的比例
9. 计算资金净值 totalAmount，以及净值的 比例

~~~~json
[
	{
		"code": "000000",
		"name": "XXXX",
		"date": "2015-12-12",
		"volume": 1000,
		"turnover": 1.0,
		"proportion": 1.0,
		"reasonCodeSet": [1, 2, 3],
		"traders": [
			{
				"traderId": 1,
				"appearTimes": 10,
				"successRatio": 0.1,
				"buy": 1.0,
				"sell": 1.0,
				"total": 1.0
			}
		]
	}
]
~~~~

先生成上面的数据集, 然后手工进行分类算法的分析, 直到总结出合理的算法, 用 F# 实现出来.

# 决策树生成算法

先按照 target, 分成两列, 一列成功, 一列失败, 轮流取两列的值, 进行决策树生成, 如果某一列取完, 则只取另一列. 直到所有的数据都用完.

1. 创建一个 Branch, 在 Branch 里设置判别标准. 创建两个 Leaf, 分别表示


## 有限集合

## 无限集合
