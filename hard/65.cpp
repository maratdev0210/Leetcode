#include <bits/stdc++.h>

using namespace std;

vector <char> repeated = {'+', '-', '.', 'e'};
vector <char> allowed = {'+', '-', '.', 'e', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
vector <char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool is_repeated(string s, int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            bool ok = false;
            for (int j = 0; j < 4; j++) {
                if (s[i] == repeated[j]) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                return true;
            }
        }
    }
    return false;
}

bool has_other_chars(string s, int n) {
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (char ch: allowed) {
            if (s[i] == ch) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            return true;
        }
    }
    return false;
}

bool is_decimal(string s, int n) {
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            return true;
        }
    }
    return false;
}

bool valid_signs(string s, int n) {
    if (n == 1) {
		if (s[0] == '-' || s[0] == '+') {
			return false;
		}
        return true;
    }
    for (int i = 1; i < n; i++) {
        if ((s[i - 1] == '-' && s[i] == '+') || (s[i - 1] == '+' && s[i] == '-')) {
            return false;
        }
    }
    return true;
}

int exponent_count(string s, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'e') {
            count++;
        }
    }
    return count;
}

bool is_integer(string s, int n) {
	if (!valid_signs(s, n)) {
		return false;
	}
	bool ok = true;
    for (int i = 1; i < n; i++) {
        if (s[i] == '+' || s[i] == '-') {
        ok = false;
        break;
        }
    }
    if (!ok) {
        return false;
    } 

	return true;
}

bool is_number(string s) {
	for (int i = 0; i < listt.size(); i++) {
		if (s == listt[i]) {
			return false;
		}
	}
    int n = s.size();
    if (is_repeated(s, n) || has_other_chars(s, n)) {
        return false;
    }
	if (n > 1) {
		if (s[n - 1] == '.' && s[n - 2] == '-') {
			return false;
		}
		if (s[n - 1] == '.' && s[n - 2] == '+') {
			return false;
		}
	}
	if (n > 1) {
		for (int i = 1; i < n; i++) {
			if (s[i] == '+' && s[i - 1] == '-') {
				return false;
			}
			if (s[i] == '-' && s[i - 1] == '+') {
				return false;
			}
		}
	}
	if (n > 1) {
		for (int i = 1; i < n; i++) {
			if (s[i] == '-' && s[i - 1] == '.') {
				return false;
			}
		}
	}
    if (!is_decimal(s, n)) {
		if (s[n - 1] == '-' || s[n - 1] == '+') {
			return false;
		}
        // integer number
        if (!valid_signs(s, n)) {
            return false;
        }
        if (exponent_count(s, n) == 0) {
			if (is_integer(s, n)) {
				return true;
			}
			return false;
        } else {
			if (exponent_count(s, n) > 1) {
				return false;
			}
			if (s[0] == 'e') {
				return false;
			}
			if (n == 1) {
				if (s[0] == '-' || s[0] == '+') {
					return false;
				}
				return true;
			}
			for (int i = 1; i < n; i++) {
				if (s[i] == 'e' && (s[i - 1] == '-' || s[i - 1] == '+')) {
					return false;
				}
			}
			int pos = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == 'e') {
					pos = i;
					break;
				}
			}
			bool ok = true;
			for (int i = 1; i < n; i++) {
				if ((s[i] == '+' || s[i] == '-') && i < pos) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				return false;
			} 
			
			string new_s = "";
			for (int i = pos + 1; i < n; i++) {
				new_s += s[i];
			}
			if (pos == n - 1) {
				return false;
			}
			int sz = new_s.size();
			if (is_integer(new_s, sz)) {
				return true;
			}
			return false;
		}
    }
	if (exponent_count(s, n) == 0) {
		for (int i = 1; i < n; i++) {
			if (s[i] == '+' || s[i] == '-') {
				return false;
			}
		}
		if (n == 1 && s[0] == '.') {
			return false;
		}
		if (s[n - 1] == '-' || s[n - 1] == '+') {
			return false;
		}
		if (n == 2) {
			if (s[0] == '.' && (s[1] == '-' || s[1] == '+')) {
				return false;
			}
			if ((s[0] == '-' || s[0] == '+') && (s[1] == '.')) {
				return false;
			}
			return true;
		}
		string cur = "";
		int dot = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '.') {
				dot++;
				if (cur.size() == 1) {
					continue;
				}
				if (!is_integer(cur, cur.size())) {
					return false;
				}
				cur = "";
			}
			if (i > 0) {
				if (s[i - 1] == '.' && (s[i] == '-' || s[i] == '+')) {
					return false;
				}
				cur += s[i];
			}
		} 
		if (dot > 1) {
			return false;
		}
		if (s[n - 1] == '.' && dot > 1) {
			return false;
		}
		return true;
	} else if (exponent_count(s, n) == 1) {
		if (s[0] == 'e') {
			return false;
		}
		if (s[n - 1] == 'e') {
			return false;
		}
		if (s[n - 1] == '+' || s[n - 1] == '-') {
			return false;
		}
		if (n == 2) {
			if (s[0] == '.') {
				if (s[1] == 'e' || s[1] == '-' || s[1] == '+') {
					return false;
				}
				return true;
			} 
			if (s[0] == 'e' || s[0] == '-' || s[0] == '+') {
				return false;
			}
			return true;
		}
		string cur1 = "";
		int pos = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '.') {
				pos = i;
				break;
			} 
			cur1 += s[i];
		}
		if (s[n - 2] == 'e' && s[n - 1] == '.') {
			return false;
		}
		if (s[0] == '.' && s[1] == 'e') {
			return false;
		}
		int pos2 = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'e') {
				pos2 = i;
				break;
			}
		}
		if (pos2 != -1) {
			for (int i = pos2; i < n; i++) {
				if (s[i] == '.') {
					return false;
				}
			}
		}
		
		if (cur1.size() == 2) {
			if (cur1[0] == '.' && (cur1[1] == '-' || cur1[1] == '+')) {
				return false;
			}
			if ((cur1[0] == '-' || cur1[0] == '+') && (cur1[1] == '.')) {
				return false;
			}
			return true;
		}
		string cur2 = "";
		for (int i = 0; i < cur2.size(); i++) {
			if (cur1[i] == '.') {
				
				if (cur2.size() == 1) {
					continue;
				}
				if (!is_integer(cur2, cur2.size())) {
					return false;
				}
				cur2 = "";
			}
			if (i > 0) {
				if (cur1[i - 1] == '.' && (cur1[i] == '-' || cur1[i] == '+')) {
					return false;
				}
				cur2 += cur1[i];
			}
		} 
		string new_s = "";
		for (int i = pos + 1; i < n; i++) {
			new_s += s[i];
		}
		if (pos == n - 1) {
			return false;
		}
		if (new_s.size() == 1) {
			if (new_s[0] == '.') {
				return true;
			}
			if (new_s[0] == 'e' || new_s[0] == '-' || new_s[0] == '+') {
				return false;
			}
			return true;
		}
		if (new_s.size() == 2) {
			if (new_s[0] == '.' && (new_s[1] == '-' || new_s[1] == '+')) {
				return false;
			}
			if ((new_s[0] == '-' || new_s[0] == '+') && (new_s[1] == '.')) {
				return false;
			}
			return true;
		}
		string cur4 = "";
		for (int i = 0; i < new_s.size(); i++) {
			if (new_s[i] == '.') {
				if (cur4.size() == 1) {
					continue;
				}
				if (!is_integer(cur4, cur4.size())) {
					return false;
				}
				cur4 = "";
			}
			if (i > 0) {
				if (new_s[i - 1] == '.' && (new_s[i] == '-' || new_s[i] == '+')) {
					return false;
				}
				cur4 += new_s[i];
			}
		} 
		return true;
	}
    return false;
}

class Solution {
	public:
	bool isNumber(string s) {
		return is_number(s);
	}
};