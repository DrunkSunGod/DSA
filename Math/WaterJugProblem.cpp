 bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if( targetCapacity%gcd(jug1Capacity, jug2Capacity) == 0 && (jug1Capacity + jug2Capacity >= targetCapacity))
            return true ; 
        return false ;
    }
// Bezout's Theorem : any linear combination of a and b will be a multiple of the gcd of a and b.
// aX + bY = k*gcd(a,b) ; 
