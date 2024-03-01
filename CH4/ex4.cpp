/*Ex 4-4: It’s time to make good on a promise. somewhere in this chapter, we said we’d look for someone “who is older than 21, younger than 35, is female, has a bachelor’s or master’s degree, is unmarried, and speaks hindi or Urdu.” Write a program that prompts the user for these qualifications and then outputs whether they qualify for these very specific requirements. To this end, you should define an integer variable age, a character variable gender (to hold 'm' for male, 'f' for female, etc.), a variable degree of an enumeration type AcademicDegree (possible values: none, associate, bachelor, professional, master, doctor), and three Boolean variables: married, speaks Hindi, and speaks Urdu. Emulate a trivial online job interview, ignore any and all flagrant age and sex discrimination issues, and query your applicant for input on all these variables. people who enter invalid values do not qualify, of course, and should be ruled out as early as possible.*/

import std;

int main()
{
	enum AcademicDegree { none, bachelor, professional, master, doctorate };
	
	AcademicDegree applicantHighestEdu{};

	unsigned short minValidInputAge{ 18 };
	unsigned short maxValidInputAge{ 80 };
	unsigned short minValidAcceptAge{ 21 };
	unsigned short maxValidAcceptAge{ 35 };

	unsigned int applicantAge{};
	unsigned char applicantGender{};
	unsigned char applicantDegree{};
	unsigned char applicantYesNoChoiceVar{};

	bool isMarried{ false };
	bool isHindiSpeaker{ false };
	bool isUrduSpeaker{ false };


	std::print("Please provide a valid age (18-80): ");
	std::cin >> applicantAge;

	if (applicantAge < minValidInputAge || applicantAge > maxValidInputAge)
	{
		std::println("Invalid age input. Please try again...");
		return 1;
	}

	std::print("Please provide your gender ([m]ale, [f]emale, [p]refer not to disclose): ");
	std::cin >> applicantGender;

	if (applicantGender != 'p' && applicantGender != 'm' && applicantGender != 'f')
	{
		std::println("Invalid gender input. Please try again...");
		return 1;
	}

	std::println("\nThank you for your patience. Please answer yes / no to these questions, any other input will be considered a negative answer...");

	std::print("\nWould you consider yourself to be fluent in Hindi (y/n)? ");
	std::cin >> applicantYesNoChoiceVar;

	applicantYesNoChoiceVar == 'y' ? isHindiSpeaker = true : isHindiSpeaker = false;

	std::print("Would you consider yourself to be fluent in Urdu (y/n)? ");
	std::cin >> applicantYesNoChoiceVar;

	applicantYesNoChoiceVar == 'y' ? isUrduSpeaker = true : isUrduSpeaker = false;

	std::print("Are you married? (y/n)? ");
	std::cin >> applicantYesNoChoiceVar;

	applicantYesNoChoiceVar == 'y' ? isMarried = true : isMarried = false;

	std::print("\nFinally, please provide your highest education level ([n]one, [b]achelor, [p]rofessional, [m]aster, [d]octorate): ");
	std::cin >> applicantDegree;

	switch (applicantDegree)
	{
	case 'n':
		applicantHighestEdu = AcademicDegree::none;
		break;
	case 'p':
		applicantHighestEdu = AcademicDegree::professional;
		break;
	case 'd':
		applicantHighestEdu = AcademicDegree::doctorate;
		break;
	case 'b':
		applicantHighestEdu = AcademicDegree::bachelor;
		break;
	case 'm':
		applicantHighestEdu = AcademicDegree::master;
		break;
	default:
		std::println("Possible invalid input. Default selected: none...");
		applicantHighestEdu = AcademicDegree::none;
		break;
	}

	if ((isHindiSpeaker || isUrduSpeaker) && 
		!isMarried && 
		((minValidAcceptAge < applicantAge) || (applicantAge < maxValidAcceptAge)) &&
		(applicantHighestEdu == AcademicDegree::bachelor || applicantHighestEdu == AcademicDegree::master) && 
		applicantGender == 'f')
	{
		std::println("\nCongratulations, your application was successful...");
	}
	else
	{
		std::println("\nUnfortunately, your application wasn't successful, please try again in the future...");
	}

	return 0;
}