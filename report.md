
investigation: 
travel_variant: preorder
  experiments: 
- experiment: 
    number: 1
    input_data: 
      buffer_size: 32 kb
    results: 
      duration: 77 ns
- experiment: 
    number: 2
    input_data: 
      buffer_size: 64 kb
    results: 
      duration: 79 ns
- experiment: 
    number: 3
    input_data: 
      buffer_size: 128 kb
    results: 
      duration: 79 ns
- experiment: 
    number: 4
    input_data: 
      buffer_size: 256 kb
    results: 
      duration: 177 ns
- experiment: 
    number: 5
    input_data: 
      buffer_size: 512 kb
    results: 
      duration: 226 ns
- experiment: 
    number: 6
    input_data: 
      buffer_size: 1024 kb
    results: 
      duration: 224 ns
- experiment: 
    number: 7
    input_data: 
      buffer_size: 2 mb
    results: 
      duration: 214 ns/10
- experiment: 
    number: 8
    input_data: 
      buffer_size: 4 mb
    results: 
      duration: 258 ns
- experiment: 
    number: 9
    input_data: 
      buffer_size: 8 mb
    results: 
      duration: 1841 ns

<img src="preorder.png" width="200" height="50"/>


investigation: 
travel_variant: postorder
  experiments: 
- experiment: 
    number: 1
    input_data: 
      buffer_size: 32 kb
    results: 
      duration: 55 ns
- experiment: 
    number: 2
    input_data: 
      buffer_size: 64 kb
    results: 
      duration: 78 ns
- experiment: 
    number: 3
    input_data: 
      buffer_size: 128 kb
    results: 
      duration: 76 ns
- experiment: 
    number: 4
    input_data: 
      buffer_size: 256 kb
    results: 
      duration: 171 ns
- experiment: 
    number: 5
    input_data: 
      buffer_size: 512 kb
    results: 
      duration: 234 ns
- experiment: 
    number: 6
    input_data: 
      buffer_size: 1024 kb
    results: 
      duration: 237 ns
- experiment: 
    number: 7
    input_data: 
      buffer_size: 2 mb
    results: 
      duration: 235 ns
- experiment: 
    number: 8
    input_data: 
      buffer_size: 4 mb
    results: 
      duration: 248 ns
- experiment: 
    number: 9
    input_data: 
      buffer_size: 8 mb
    results: 
      duration: 1844 ns

<img src="postorder.png" width="200" height="50"/>


investigation: 
travel_variant: randorder
  experiments: 
- experiment: 
    number: 1
    input_data: 
      buffer_size: 32 kb
    results: 
      duration: 90 ns
- experiment: 
    number: 2
    input_data: 
      buffer_size: 64 kb
    results: 
      duration: 89 ns
- experiment: 
    number: 3
    input_data: 
      buffer_size: 128 kb
    results: 
      duration: 102 ns
- experiment: 
    number: 4
    input_data: 
      buffer_size: 256 kb
    results: 
      duration: 157 ns
- experiment: 
    number: 5
    input_data: 
      buffer_size: 512 kb
    results: 
      duration: 218 ns
- experiment: 
    number: 6
    input_data: 
      buffer_size: 1024 kb
    results: 
      duration: 207 ns
- experiment: 
    number: 7
    input_data: 
      buffer_size: 2 mb
    results: 
      duration: 254 ns
- experiment: 
    number: 8
    input_data: 
      buffer_size: 4 mb
    results: 
      duration: 266 ns
- experiment: 
    number: 9
    input_data: 
      buffer_size: 8 mb
    results: 
      duration: 1846 ns

<img src="randorder.png" width="200" height="50"/>
