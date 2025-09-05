import myfuncs
import numpy

print("EXPONENTIAL DIFFERENCES")
for k in [5,10]:
    print("x value: " + str(k))
    exp_diff = myfuncs.exp(k) - numpy.exp(k)
    print(f"Difference in exp values: {exp_diff}")

print("SQUARE ROOT DIFFERENCES")
for k in [256, 1024]:
    print("x value: " + str(k))
    sqrt_diff = myfuncs.sqrt(k) - numpy.sqrt(k)
    print(f"Differences in sqrt values: {sqrt_diff}")

print("NATURAL LOG DIFFERENCES")
for k in [2,3]:
    print("x value: " + str(k))
    ln_diff = myfuncs.ln(k) - numpy.log(k)
    print(f"Difference in ln values: {ln_diff}")
