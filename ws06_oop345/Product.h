#ifndef _TN_PRODUCT_H_
#define _TN_PRODUCT_H_

#include "iProduct.h"

namespace w6 
{
	class Product : public iProduct
	{
	protected:
		int prdNum;
		float prdCost;

	public:
		double getPrice() const;
		void display(std::ostream&) const;
	};

}


#endif 