# Clear HTML

## Requirements

1. Implement a class to count the repetitions of each word on a website.
2. Do not count connectors: *the*, *for*, *a*, *to*, *was*, etc.
3. Use *maps*, *arrays*, *vectors*, and the *algorithm* library.
4. Only use *iterators* to access the elements of a container.
5. The test will be carried out with the website: [https://norvig.com/y10k.html](https://norvig.com/y10k.html).

### 1. Random words

```
CounterC("https://norvig.com/y10k.html");

cout << C("think"); // Result: 5
cout << C("bug"); // Result: 7
cout << C("bugs"); // Result: 1
```

### 2. Ranking

```
vector<string> rank = C.ranking();

cout << rank[0]; // ilsa (with 30 repetitions)
cout << rank[1]; // time (with 20 repetitions)
cout << rank[2]; // said (with 18 repetitions)
cout << rank[3]; // russell (with 16 repetitions)
cout << rank[4]; // still (with 10 repetitions)
```

### 3. Stop Words

*Tags* and *urls* should not be counted, only text.

```
cout << C("<p>"); // Result: 0
cout << C("<html>"); // Result: 0
cout << C("http"); // Result: 0
cout << C("/"); // Result: 0
```