# dsproj

## Benchmark (pandas, numpy)

### Python

The `pandf.py` generates a Pandas DataFrame containing three columns with random values: `normal`, `log_normal`, and `exponential`. It then calculates the mean values for each of the columns and prints.

The "timestamps" variable is a Pandas DatetimeIndex object generated using the pd.date_range() function, which creates a sequence of timestamps starting from "1970-01-01" and ending at "1971-08-15", with a frequency of one second ("freq='S'"). The other columns are generated using numpy's random number generation functions.

The DataFrame is then indexed using the "set_index()" method, which sets the "timestamp" column as the DataFrame's index. However, it doesn't modify the original DataFrame, so it's necessary to either re-assign the DataFrame after applying "set_index()", or pass "inplace=True" as an argument.

Finally, the means for each column are calculated using the "mean()" method, and the elapsed time for loading the data and calculating the means is displayed.

```
time /bin/python /home/leanne/work/dsproj/pandf.py
Starting ...
All data loadings are done. Calculating means ... 3
5.824825917943803e-05, 1.6482749633962486, 1.0001457369839524
0, 3 All done
/bin/python /home/leanne/work/dsproj/pandf.py  3.06s user 1.99s system 141% cpu 3.573 total
```

### C++

```
time ./dsproj
Starting ...
All data loadings are done. Calculating means ... 13
1, 1.64841, 1.00012
0, 13 All done
./dsproj  14.13s user 0.30s system 98% cpu 14.612 total
```