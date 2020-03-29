sort(all(${1:vec}), [&](auto a, auto b){
  return ${2:f}(a) < ${2:f}(b);
});