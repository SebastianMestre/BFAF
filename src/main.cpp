#include <fstream>
#include <iostream>

#include <cstring>

constexpr auto usage_string = "-- BrainFuck Auto Formatter --\n"
                              "-- by Sebastian Mestre --\n"
                              "-- usage: bfaf [-o <name>] <file>\n"
                              "-- default out is <file>.formatted\n";
void bad_usage()
{
	std::cerr << usage_string;
	std::terminate();
}

constexpr auto isBfToken(char c) -> bool
{
	constexpr char validTokens[] = { '[', ']', '<', '>', '+', '-', '.', ',' };
	for (char valid : validTokens)
		if (c == valid)
			return true;
	return false;
}

constexpr auto isWhitespace(char c) -> bool { return c == ' ' || c == '\t' || c == '\n'; }

int main(int argc, char** argv)
{
	if (argc < 2)
		bad_usage();

	std::string output_path;
	std::string input_path;

	{
		bool has_input = false;
		bool has_output = false;

		for (int i = 1; i < argc; ++i) {
			if (argv[i][0] == '-') {
				if (strcmp(argv[i], "-o") == 0) {
					output_path = argv[++i];
					has_output = true;
				}
				else {
					bad_usage();
				}
			}
			else {
				if (not has_input) {
					input_path = argv[i];
					has_input = true;
				}
				else {
					bad_usage();
				}
			}
		}

		if (not has_input) {
			bad_usage();
		}

		if (not has_output) {
			output_path = input_path + ".formatted";
		}
	}

	{
		std::string file_contents;

		{
			std::ifstream in_file{ input_path };
			std::string line;
			while (std::getline(in_file, line)) {
				file_contents.append(line);
			}
		}

		std::ofstream out_file{ output_path };

		int depth = 0;
		char last = '\0';
		int equal_count = 0;
		for (int i = 0; i < file_contents.size(); ++i) {
			char c = file_contents[i];
			if (isWhitespace(c) && last != '\0') {
				continue;
			}
			if (not isBfToken(c)) {
				if (last != '\0')
					out_file << '\n';
				out_file << c;
				last = '\0';
				int equal_count = 0;
				continue;
			}
			if (i+2 < file_contents.size() && c == '[') {
				if (file_contents[i + 1] == '+' || file_contents[i + 1] == '-') {
					if (file_contents[i + 2] == ']') {
						out_file << '\n';
						for (int i = 0; i < depth; ++i)
							out_file << '\t';
						out_file << '[' << file_contents[i + 1] << "]";
						i += 2;
						last = ']';
						equal_count = 0;
						continue;
					}
				}
			}

			if (c == ']') {
				depth--;
			}

			if (c != last || c == '[' || c == ']') {
				equal_count = 0;
				out_file << '\n';
				for (int i = 0; i < depth; ++i)
					out_file << '\t';
			}
			else {
				equal_count++;
				if (equal_count % 4 == 0) {
					out_file << ' ';
				}
				if (equal_count == 16) {
					out_file << '\n';
					for (int i = 0; i < depth; ++i)
						out_file << '\t';
					equal_count = 0;
				}
			}

			if (c == '[') {
				depth++;
			}

			out_file << c;
			last = c;
		}
	}
}
