#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

class BaseException
{
	protected:
		char *message;
	public:
		BaseException(void);
		BaseException(const char* newMessage);
		BaseException(const BaseException&newException);
		~BaseException(void);

		void setMessage(const char*newMessage);

		const char* getMessage(void) const;
};

#endif //BASEEXCEPTION_H