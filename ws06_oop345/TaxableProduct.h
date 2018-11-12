#ifndef __TN_TAX_PRD_H_
#define __TN_TAX_PRD_H_

#include "Product.h"

namespace w6
{
	class taxableProduct : public Product
	{
		enum tax{NONE, HST, PST}; 
		static double rate[3];

	public:
		double getPrice() const;
		void display(std::ostream& os) const;
	};
}


#endif 