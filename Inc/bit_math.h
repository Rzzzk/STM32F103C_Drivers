/**********************************************************************/
/*******************  Author  : Rezk Ahmed     ************************/
/*******************  Date    : 26 Jun 2023    ************************/
/*******************  Layer   : LIB            ************************/
/*******************  Version : 1.0            ************************/
/**********************************************************************/



#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT)               (REG|=(1<<BIT))                     // set a bit in the register
#define CLR_BIT(REG,BIT)               (REG&=(~(1<<BIT)))                  // clear a bit in the register
#define TOG_BIT(REG,BIT)               (REG^=(1<<BIT))                     // toggle a bit in the register
#define GET_BIT(REG,BIT)               ((REG>>BIT)&1)                      // Output is 0 or 1

#define WRITE_BIT(REG,BIT,VALUE)       (REG&=(~(1<<BIT)))|(VALUE<<BIT)



#endif /* BIT_MATH_H_ */
