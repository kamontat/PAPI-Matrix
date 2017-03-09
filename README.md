# Content 
- [By](#by)
- [Runner](#runner)
- [Question & Answer](#question-&-answer)
  - [O1](#-o1)
  - [O2](#-o2)
  - [O3](#-o3)
  - [Os](#-os)
  - [Ofast](#-ofast)
  - [foptimize-register-move](#-foptimize-register-move)
  - [fsched2-use-superblocks](#-fsched2-use-superblocks)
  - [funroll-all-loops](#-funroll-all-loops)
- [Compare](#compare)
  - [Time](#compare-by-time:)
  - [MIPs](#compare-mips-(million-instructions-per-second):)


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
|MIPs          |5597    |
|Execution time|0.002428|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |1308    |
|MIPs          |443     |
|Execution time|17.2829 |

### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |286359  |
|MIPs          |266     |
|Execution time|3351.946|
> more at `result/O3`


## -Os
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |
|MIPs          |5663    |
|Execution time|0.002751|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |789     |
|MIPs          |579     |
|Execution time|16.67639|


### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |235152  |
|MIPs          |342     |
|Execution time|3341.166|
> more at `result/Os`


## -Ofast
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |
|MIPs          |5533    |
|Execution time|0.002456|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |3207    |
|MIPs          |419     |
|Execution time|18.28632|


### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |413931  |
|MIPs          |266     |
|Execution time|3352.994|
> more at `result/Ofast`


## -foptimize-register-move
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |
|MIPs          |5660    |
|Execution time|0.006147|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |1719    |
|MIPs          |1605    |
|Execution time|17.85976| 

### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |382218  |
|MIPs          |1038    |
|Execution time|3387.372|
> more at `result/foptimize-register-move`


## -fsched2-use-superblocks
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |
|MIPs          |2745    |
|Execution time|0.012673|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |7614    |
|MIPs          |1529    |
|Execution time|18.74752|

### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |211125  |
|MIPs          |1031    |
|Execution time|3409.966|
> more at `result/fsched2-use-superblocks`


## -funroll-all-loops
### 100
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |0       |  
|MIPs          |5564    |
|Execution time|0.006253|

### 1000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |636     |
|MIPs          |1631    |
|Execution time|17.57929|

### 5000
|Head          |Result  |
|:------------:|:------:|
|FLOPS         |238473  |
|MIPs          |1005    |
|Execution time|3498.148|
> more at `result/funroll-all-loops`



# Compare 

## Compare By Time: 
- O1 (0.0047, 18.957, 3933.766)
- O2 (0.0044, 21.145, 3515.132)
- O3 (0.00242, 17.282, 3351.946)
- Os (0.0027, 16.676, 3341.166)
- Ofast (0.00245, 18.286, 3352.994)
- fo (0.0061, 17.859, 3387.372)
- fs (0.0126, 18.747, 3409.966)
- fu (0.0062, 17.579, 3498.148)

#### Small
**Fastest** : O3 < Ofast < Os < O2 < O1 < fo < fu < fs : **Slowest**

#### Mid
**Fastest** : Os < O3 < fu < fo < Ofast < fs < O1 < O2 : **Slowest**

#### Big
**Fastest** : Os < O3 < Ofast < fo < fs < fu < O2 < O1 : **Slowest**


## Compare MIPs (Million Instructions per Second): 
- O1 (2873, 403, 226)
- O2 (3034, 362, 253)
- O3 (5597, 443, 266)
- Os (5663, 579, 342)
- Ofast (5533, 419, 266)
- fo (5660, 1605, 1038)
- fs (2745, 1529, 1031)
- fu (5564, 1631, 1005)

#### Small
**Most** : Os > fo > O3 > fu > Ofast > O2 > O1 > fs : **Less**

#### Mid
**Most** : fu > fo > fs > Os > O3 > Ofast > O1 > O2 : **Less** 

#### Big
**Most** : fo > fs > fu > Os > O3 = Ofast > O2 > O1 : **Less** 
