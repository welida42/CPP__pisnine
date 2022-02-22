#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
	Bureaucrat();
public:
	Bureaucrat(std::string Name, int Grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &operand);

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& operand);

#endif