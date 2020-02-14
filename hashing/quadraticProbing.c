/**
 * Hash table: (collision handling)
 *
 * Quadratic Probing: there's a theorem that if the size of hash table is 
 * 4k+3,(k is a positive integer, 4k+3 is also a prime), then quadratic 
 * probing can detect every cell of hash table
 *
 * Double Hashing: like quadratic probling, when we choose function 
 * h2(key) = p-(key mod p) (p<TableSize, p and TableSize are both prime), it
 * can detect every cell
 *
 *                           / 1/(1-α) (ASLu and insertion)
 * p (i.e. Expected value) = 
 *                           \ -1/α * ln(1-α) (ASLs)
 */
Position Find(HashTable H, ElementType Key) {
	Position CurrentPos, NewPos;
	int CNum = 0;
	NewPos = CurrentPos = Hash(Key, H->TableSize);
	while (H->Cells[NewPos].Info!=Empty && H->Cells[NewPos].Data!=Key) {
		if (++CNum%2) {
			NewPos = CurrentPos + (CNum+1)*(CNum+1)/4;
			if (NewPos >= H->TableSize)
				NewPos = NewPos % H->TableSize;
		} else {
			NewPos = CurrentPos - CNum*CNum/4;
			while (NewPos < 0)
				NewPos += H->TableSize;
		}
	}
	return NewPos;
}
bool Insert(HashTable H, ElementType Key) {
	Position Pos = Find(H, Key);
	if (H->Cells[Pos].Info != Legitimate) {
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		return true;
	} else {
		printf("The key value already exists!\n");
		return false;
	}
}
