// beware [(elem, i)]
vector<pair<decltype(${1:vec})::value_type, int>> ${2:res}(${1:vec}.size());
rep(i, ${1:vec}.size()) ${2:res}[i] = make_pair(${1:vec}[i], i);
