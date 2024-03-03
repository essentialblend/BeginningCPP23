/*Ex 5-7: Write a program that will read and store an arbitrary sequence of records relating to products. each record includes three items of data—an integer product number, a quantity, and a unit price. For product number 1001, the quantity is 25, and the unit price is $9.95. Because you do not yet know how to create compound types, simply use three different array-like sequences to represent these records. The program should output each product on a separate line and include the total cost. The last line should output the total cost for all products.*/

import std;

struct ProductData {
	int prodCode{};
	int prodQty{};
	double prodUnitPriceUSD{};
	double totalCostUSD{};
};

static bool letUserCreateRec(std::vector<ProductData>& masterList, char& userChoice);

int main()
{
	bool userWantsToCreateRec{ false };
	char userChoice{};
	std::vector<ProductData> masterList{};
	double finalTotalCost{};

	// Let user input all records.
	do { userWantsToCreateRec = letUserCreateRec(masterList, userChoice); } 
	while (userWantsToCreateRec);

	// Display a table.
	std::println(" {:-^103}","");
	std::println("|{:^25}|{:^25}|{:^25}|{:^25}|", "Product", "Quantity", "Unit Price", "Total Cost");
	std::println(" {:-^103}", "");
	
	for (auto& rec : masterList)
	{
		std::string unitPrice{ std::format("${:.2f}", rec.prodUnitPriceUSD)};
		std::string totalPrice{ std::format("${:.2f}", rec.totalCostUSD) };
		std::println("|{:^25}|{:^25}|{:^25}|{:^25}|", rec.prodCode, rec.prodQty, unitPrice, totalPrice);
		finalTotalCost += rec.totalCostUSD;
	}
	std::string finalTotalPriceString{ std::format("${:.2f}", finalTotalCost) };
	std::println(" {:-^103}", "");
	std::println("|{:^25}|{:^25}|{:^25}|{:^25}|", "", "", "", finalTotalPriceString);
	std::println(" {:-^103}", "");

	return 0;
}

static bool letUserCreateRec(std::vector<ProductData>& masterList, char& userChoice)
{
	ProductData dataObj;

	std::print("Please enter a product code (int), quantity (int), and unit price (float) ($), separated by spaces (a b c): ");
	std::cin >> dataObj.prodCode >> dataObj.prodQty >> dataObj.prodUnitPriceUSD;

	for (auto& rec : masterList)
	{
		if (rec.prodCode == dataObj.prodCode)
		{
			std::print("Product already exists, try again (y/n): ");
			std::cin >> userChoice;

			if (userChoice == 'y')
			{
				return true;
			}
			else
				return false;
		}
	}

	dataObj.totalCostUSD = dataObj.prodQty * dataObj.prodUnitPriceUSD;
	masterList.push_back(dataObj);

	std::print("Record created, do you wish to create another record (y/n): ");
	std::cin >> userChoice;
	if (userChoice == 'y')
	{
		return true;
	}
	else
		return false;
}