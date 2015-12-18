# randcer

A simple C program to test certainties in random number series

The purpose of this program is to find out any implicit hidden rules behind random numbers, with the assumption that the numbers are generated randomly (technically this has to depend on the algorithm used, also in reality most of them, if not all, are just pseudo-randoms). For example:

./randcer 20 // gives 20 combinations of numbers

O:E - Odd : Even ratio
B:S - Big : Small ratio
SUM: Sum of all numbers in one series
COT: continuous numbers count (e.g. the series "1	19	20	21	22	32" has COT of 3, 19-20, 20-21 and 21-22)


I	II	III	IV	V	VI	O:E	B:S	SUM	COT
-----------------------------------------------------------------------------
4	16	20	21	22	23	2:4	4:2	106	3	
2	2	4	12	24	26	0:6	2:4	70	0	
4	6	7	11	14	24	2:4	1:5	66	1	
1	22	29	32	33	33	4:2	5:1	150	1	
15	17	21	24	28	29	4:2	5:1	134	1	
7	12	13	13	20	31	4:2	2:4	96	1	
4	7	7	11	16	18	3:3	1:5	63	0	
2	14	21	23	23	31	4:2	4:2	114	0	
13	14	15	19	22	24	3:3	3:3	107	2	
1	5	11	13	23	24	5:1	2:4	77	1	
1	6	6	9	20	26	2:4	2:4	68	0	
3	5	6	23	27	33	5:1	3:3	97	1	
6	11	22	30	31	33	3:3	4:2	133	1	
1	8	13	15	19	28	4:2	2:4	84	0	
1	10	17	21	25	33	5:1	4:2	107	0	
1	19	20	21	22	32	3:3	5:1	115	3	
4	5	5	5	11	33	5:1	1:5	63	1	
5	23	26	26	29	31	4:2	5:1	140	0	
6	19	24	30	31	33	3:3	5:1	143	1	
7	19	27	30	30	31	4:2	5:1	144	1

