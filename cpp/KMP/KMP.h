#include <iostream>
#include <string>

void PMT(const std::string &str, std::string &pmt) {
    pmt = std::string(str.size(), '\0');
    for (size_t i = 0; i < str.size(); i++) {
        std::string ss = str.substr(0, i+1);
        std::cout << "substr: " << ss << std::endl;
        size_t pmt_val = 0;
        for (size_t prefix_idx = 0, suffix_idx = ss.size() - 1;
             prefix_idx < ss.size() - 1; prefix_idx ++, suffix_idx --) {
            std::string prefix = ss.substr(0, prefix_idx+1);
            std::string suffix = ss.substr(suffix_idx);

            std::cout << "prefix: " << prefix << std::endl;
            std::cout << "suffix: " << suffix << std::endl;

            if (prefix == suffix)
                pmt_val = prefix.size();
        }
        pmt[i] = pmt_val;
    }
}

int KMP(const std::string &str, const std::string &substr) {
    std::string pmt;
    PMT(substr, pmt);
    size_t p = 0, q = 0;
    while(p < str.size() && q < substr.size()) {
        std::cout << std::string(p, ' ') << "|" << std::endl;
        std::cout << str << std::endl;
        std::cout << std::string(p-q, ' ') << substr << std::endl;

        if (str[p] == substr[q]) {
            p += 1, q += 1;
            if (q == substr.size()) {
                std::cout << "Found" << std::endl;
                return p - substr.size();
            }
        } else {
            if (q > 0) {
                std::cout << "Move back: ";
                std::cout << "q = " << q << ", ";
                std::cout << "PMT = " << int(pmt[q-1]) << std::endl;
                q -= q - pmt[q-1];
            } else {
                p += 1;
                q = 0;
                std::cout << "New start" << std::endl;
            }
        }
        std::cout << std::endl;
    }

    return -1;
}

