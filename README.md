# By
- Kamontat Chantrachirathumrong 5810546552
- Soraya Saenna 5810546056

# Runner
- Linux Server (Ubuntu 14.04.5 x64)
  - model string is Intel(R) Xeon(R) CPU E5-2620 0 @ 2.00GHz 
  - 512 MB Memory / 20 GB Disk

# Question & Answer
## -O1
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |
|MIPs          |2873    |
|Execution time|0.004695|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |4704    |
|MIPs          |403     |
|Execution time|18.95796|

### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |927912  |
|MIPs          |226     |
|Execution time|3933.766|
> more at `result/O1`


## -O2
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |
|MIPs          |3034    |
|Execution time|0.004478|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |2427    |
|MIPs          |362     |
|Execution time|21.14534|

### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |347880  |
|MIPs          |253     |
|Execution time|3515.132|
> more at `result/O2`


## -O3
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |
|MIPs          |5597.199|
|Execution time|0.002428|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |1308    |
|MIPs          |442.911 |
|Execution time|17.2829 |

### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |286359  |
|MIPs          |265.924 |
|Execution time|3351.946|
> more at `result/O3`


## -Os
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |
|MIPs          |5663.395|
|Execution time|0.002751|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |789     |
|MIPs          |578.892 |
|Execution time|16.67639|


### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |235152  |
|MIPs          |341.5992|
|Execution time|3341.166|
> more at `result/Os`


## -foptimize-register-move
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |
|MIPs          |5659.671|
|Execution time|0.006147|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |1719    |
|MIPs          |1605.556|
|Execution time|17.85976| 

### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |382218  |
|MIPs          |1038.228|
|Execution time|3387.372|
> more at `result/foptimize-register-move`


## -fsched2-use-superblocks
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |
|MIPs          |2745.206|
|Execution time|0.012673|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |7614    |
|MIPs          |1529.527|
|Execution time|18.74752|

### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |211125  |
|MIPs          |1031.348|
|Execution time|3409.966|
> more at `result/fsched2-use-superblocks`


## -funroll-all-loops
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |  
|MIPs          |5563.729|
|Execution time|0.006253|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |636     |
|MIPs          |1631.172|
|Execution time|17.57929|

### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |238473  |
|MIPs          |1005.350|
|Execution time|3498.148|
> more at `result/funroll-all-loops`
