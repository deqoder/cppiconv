#include <iconv.h>
#include <string>
void myconv(char const *from_set, char const *to_set, std::string const &in, std::string &out)
{
	iconv_t cd = iconv_open(to_set, from_set);
	char *in_p = (char *)in.c_str();
	size_t in_len = in.size();
	char *out_p = new char[in_len * 4];
	size_t out_len = in_len * 4;
	char *out_p_origin = out_p;
 
	iconv(cd, &in_p, &in_len, &out_p, &out_len);
	out.append(out_p_origin, out_p - out_p_origin);
	delete out_p_origin;
	iconv_close(cd);
}
