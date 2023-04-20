# __Problem C - Finding Bank Cartels__
## __Description__
Given a list of banks, along with their respective debts to other banks, you need to identify the cluster of banks with mutual debt relation that has the highest total amount of entitled money.

A debt relation between bank A and bank B means that A owes B a certain amount of money directly, or indirectly throught a "debt chain" between A and B (e.g. A owes C and C owes B).

A set of banks forms a cluster if there is a debt relation between any pair of banks in the cluster and it has the maximal size. Hence, a cluster must have at least two banks.

When bank A owes bank B some money amount M, that increases the entitlement of B by M, and decreases A's entitlement by M. Debt relations between banks inside a cluster and banks outside the cluster, those that owe or lent money to a bank in the cluster, do count for the cluster's total entitlement.

<p align="center"><img src=https://i.imgur.com/pgYc5rf.png/><br>Figure 1.</p>

Figure 1 shows an example of three banks, A, B and D, that form a cluster. Within this cluster, we have that A owes 10 to B, B owes 3 to D, and D owes 2 to A. Bank C does not belong to this cluster since it did not lent any money to other bank. Bank B is entitled 10+5-3 = 12 currency units, D is entitled 3-2 = 1 and A is entitled 2-10 = -8. Therefore, this cluster is entitled a total of 12+1-8 = 5 currency units.

## __Input__
The first line gives the number of banks (N). The banks are numbered from 1 to N. Then N lines follow, one for each bank, starting with its ID, and followed by its list of debts in the remainder of the line. The list of debts is a sequence of pairs of integers: the first integer of the pair is the amount of money owed, and the second is the ID of the bank that lent the money. The list of debts (and the line) ends with a 0. Other test cases might follow. There are at most 5000 banks and there might exist more than one test case in an input file.

## __Output__
The maximum total money entitled to the banks in a debt cluster, or "No cluster" if there are no clusters of mutual debt.
## __Example__
### __Example input__:

		4
		1 10 2 0
		2 3 4 0
		3 5 2 0
		4 2 1 0
		5
		1 3 2 5 3 0
		2 4 3 8 4 0
		3 6 4 0
		4 0
		5 6 1 0
### __Example output__:

		5
		No cluster
