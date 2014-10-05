Problem:	Convoy Problem

Description: 

		 Given lorries, all of equal capacity, to be filled with items of various weight
		 which come off a conveyor belt. Each item must be loaded onto the lorries sequentially 
		 i.e items 1 to N (for some N) go on the first lorry, items N+1, …, M (for some M) go on 
		 the second lorry, and so on. Not all lorries will be loaded to their full capacity, 
		 of course, but it is guaranteed that no single item is too heavy for a lorry. 

Required:	 
			 
		 Find the spare capacity of the convoy as the sum of squares of the unused capacity of 
		 each lorry in the convoy. We want to load the lorries in such a way to minimize the 
		 spare capacity of the convoy.

Solution:	
			
			FT(i) the best way to fill lorry from items i to n, where i starts a new lorry
			Wi = weight of item, c = capacity of lorry, if FT(k) > n, FT(k) = 0
			FT(i) = min [(c - [Wi+...+Wk])^2 + FT(k+1)] for k = 1 to n, where (Wi +... Wk) < c	

			e.g. capacity = 6, no of items 5 {1, 2, 3, 1, 1}

			FT(3) = min{ 
					(c - W3)^2 + FT(4)
					(c - W3 + W4)^2 + FT(5)
					(c - W3 + W4 + W5)^2 + FT(6)
				}


Full Description:

Consider a conveyor belt on which many items are loaded. As the items come off the belt, they are loaded onto delivery lorries. All lorries are the same and they can carry items up to a specific maximum weight (called the capacity of the lorry). Items are numbered from 1 and are of various weights.
The items must be loaded sequentially onto the lorries, i.e., items 1 to N (for some N) go on the first lorry, items N+1, …, M (for some M) go on the second lorry, and so on. Not all lorries will be loaded to their full capacity, of course, but it is guaranteed that no single item is too heavy for a lorry.
We can load the lorries in a greedy manner (load as many items as you can on this lorry and when the next item does not fit, start a new lorry) but this may lead to an unbalanced distribution of the items among the lorries.

Define the spare capacity of the convoy as the sum of squares of the unused capacity of each lorry in the convoy. We want to load the lorries in such a way to minimize the spare capacity of the convoy.

Given the capacity, c, of the lorries and sequence of weights of the items, how many items should each lorry carry, and how many lorries are required? 

The first line of data gives the value of c and the number of items, n (<= 1000). Subsequent lines contain n values, the weights of the items, in order. Some sample data are:

6  5
1  2  3 
1  1

Output: on the first line, print the number of lorries required. On the second line, print the number of items on each lorry, starting with the number of items on the first lorry, followed by the number of items on the second lorry, and so on. On the last line print the spare capacity of the convoy. For the above data, you should output:

2
2  3
10


