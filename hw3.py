from pyspark import SparkContext
import sys
if __name__ == "__main__":
    #if len(sys.argv) != 3:
     #   sys.stderr.write("Usage: hw3.py <input> <output>\n")
      #  exit(-1)
    sc = SparkContext()
    textfile = sc.textFile(sys.argv[1])
    reviews = textfile.map(lambda line: line.split(",")) \
             .map(lambda fields: (fields[0], float(fields[2]))) \
             .groupByKey() \
             .mapValues(lambda reviewList: (len(reviewList), sum(reviewList))) \
             .mapValues(lambda counts: (counts[0], round(counts[1]/counts[0], 2)))\
             .sortByKey()
             
    reviews.saveAsTextFile(sys.argv[2])
    sc.stop()
