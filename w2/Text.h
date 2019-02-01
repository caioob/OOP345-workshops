#ifndef SICT_TIME_H
#define SICT_TIME_H


namespace sict{
	class Text{
		std::string* textLines;
		int noOfLines;
	public:
		Text();
		Text(const char*);
		Text(const Text&);
		Text& operator=(const Text&);
		~Text();
		size_t size() const;
	};
}

#endif // SICT_TIMEKEEPER_H
