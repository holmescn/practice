% 龙虎榜分析
% 张鹏程
% 2015-12-11

# 龙虎榜 DataSet 准备

1. 从 SummaryData 里取出所有的日期
2. 对于每个日期, 获取当天的所有 SummaryData, 按照 StockId 排序
3. 对于每一行 SummaryData, 收集 Code, Date, Volume, Turnover, ByFloatingStocks, ReasonCode. 其中, ReasonCode作为一个集合, 可能包含 1 至 4 个值.
4. 对应每一行 SummaryData, 有一个 SummaryId, 可以获得对应的 10 个券商的交易记录. 收集 TraderId, AppearTimes, EscapeTimes, Buy, Sell, Total. 这里, TraderId, AppearTimes 都需要先统计出来, EscapeTimes 和 Target 有关, 可以先不理会. Buy, 	Sell, Total 并不是取买卖的钱数, 而是要通过钱数, 转换成占总股本的比例. 先用 Turnover / Volume 得到每股平均价格, 然后 Buy / Avg 得到股数, 最后通过对比 Volume, ByFloatingStocks 和 买卖的股数, 得到买卖占总股本的比例.

最终可用的数据包括: ByFloatingStocks, ReasonCodeSet, (TraderId, AppearTimes, EscapeTimes, Buy, Sell, Total) * 10, ReasonCodeSet 将作为一个统一的分类项, 而不是分开处理.

因为 DataSet 没有查询的需求, 所以不存在 SQLite 里了, 直接存成 JSON 文件,格式如下:

~~~~json
[
	{
		"code": "000000",
		"name": "XXXX",
		"date": "2015-12-12",
		"volume": 1000,
		"turnover": 1.0,
		"byFloatingStocks": 1.0,
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
