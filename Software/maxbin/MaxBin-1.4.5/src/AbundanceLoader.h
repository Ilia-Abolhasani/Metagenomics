#ifndef __ABUNDANCELOADER_H__
#define __ABUNDANCELOADER_H__

#include "global_inc.h"
#include <map>

class AbundanceLoader
{
	public:
		AbundanceLoader(char *file);
		~AbundanceLoader();
		bool is_open();
		int getNum();
		double getAbundance(int index);
		double getAbundance(char *header);

	private:
		// Structure
		struct str_cmp
		{
			bool operator() (char* const a, char* const b)
			{
				return (strcmp(a, b) < 0) ? true : false;
			}
		};

		// Variables
		int ADD_SIZE;
		char **header;
		double *abund;
		map<char*, double, str_cmp> abund_hash;
		int num;
		int max;
		bool open_flag;

		// Functions
		void parse(char *file);
		void _insertElement(char *h, double ab);
};


#endif
