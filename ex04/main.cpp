/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:24:10 by jweber            #+#    #+#             */
/*   Updated: 2026/01/14 09:30:20 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

#define SUCCESS 0
#define FAILURE 1


void			print_string(const std::string& a);
static int		check_args(int argc, char **argv);
static void		open_infile(std::ifstream& infile, const std::string& infilename);
static void		open_outfile(std::ofstream& outfile, const std::string& infilename);
static	int		replace_occurences(std::ifstream& infile, std::ofstream& outfile,
					   const std::string& old_str, const std::string& new_str);
static	void	create_new_line(const std::string& old_line, std::string& new_line,
					const std::string& old_str, const std::string& new_str);
std::istream&	my_getline(std::istream& stream, std::string& str);

// ok so logic would be 
// 1) check args are ok !
// 2) open inputfile
// 3) open outputfile
// 4) read line of inputfile
// 5) search replacing string
// 6) replace each occurence by new occurence
// 7) 

int	main(int argc, char **argv)
{
	std::string		infilename;
	std::string		old_str;
	std::string		new_str;
	std::ifstream	infile;
	std::ofstream	outfile;
	int				ret;

	if (check_args(argc, argv) != SUCCESS)
		return (FAILURE);
	infilename = argv[1];
	open_infile(infile, infilename);
	if (infile.fail())
		return (1);
	open_outfile(outfile, infilename);
	if (outfile.fail())
		return (1);
	old_str = argv[2];
	new_str = argv[3];
	ret = replace_occurences(infile, outfile, old_str, new_str);
	return (ret);
}

static int	check_args(int argc, char **argv)
{
	std::string str;

	if (argc != 4)
	{
		std::cout << "usage : ./sed filename str1 str2" << std::endl;
		return (FAILURE);
	}
	str = argv[2];
	if (str == "")
	{
		std::cout << "str1 cannot be empty" << std::endl;
		return (FAILURE);
	}
	return (SUCCESS);
}

void	open_infile(std::ifstream& infile, const std::string& infilename)
{
	infile.open(infilename.c_str());
	if (infile.fail())
		std::cout << "could not open file : " << infilename << std::endl;
}

void	open_outfile(std::ofstream& outfile, const std::string& infilename)
{
	std::string	outfilename;
	outfilename = infilename + ".replace";
	outfile.open(outfilename.c_str());
	if (outfile.fail())
		std::cout << "could not open file : " << outfilename << std::endl;
}

int	replace_occurences(std::ifstream& infile, std::ofstream& outfile,
					   const std::string& old_str, const std::string& new_str)
{
	std::string	old_line;

	while (!infile.fail() && !infile.eof())
	{
		my_getline(infile, old_line);
		std::string	new_line;
		if (infile.fail() && !infile.eof())
		{
			std::cout << "An error occured while reading input file" << std::endl;
			return (FAILURE);
		}
		create_new_line(old_line, new_line, old_str, new_str);
		outfile << new_line;
		if (outfile.fail())
		{
			std::cout << "An error occured while writing input file" << std::endl;
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

std::istream& my_getline(std::istream& stream, std::string& str)
{
	char	ch;

	str.clear();
	while(stream.get(ch) && ch!='\n')
		str.push_back(ch);
	if (!stream.eof() && !stream.fail())
		str.push_back(ch);
	return	(stream);
}

void	create_new_line(const std::string& old_line, std::string& new_line,
				const std::string& old_str, const std::string& new_str)
{
	size_t	find_pos;
	size_t	begin_pos;

	begin_pos = 0;
	do
	{
		find_pos = old_line.find(old_str, begin_pos);
		if (find_pos != old_line.npos)
		{
			new_line += old_line.substr(begin_pos, find_pos - begin_pos);;
			new_line += new_str;
			begin_pos = find_pos + old_str.size();
		}
		else
		{
			new_line += old_line.substr(begin_pos, old_line.size());
		}
	} while (find_pos != old_line.npos);
}
