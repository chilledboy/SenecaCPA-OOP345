#include "TaxableProduct.h"

namespace w6
{
	double taxableProduct::getPrice() const
	{
		return Product::getPrice();
	}

	void taxableProduct::display(std::ostream& os) const
	{
		Product::display(os);
		return;
	}


}