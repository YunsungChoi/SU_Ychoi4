from pyspark import SparkContext
import sys
import re

def loadStopWords(filePath):
    stopWords = sc.textFile(filePath).collect()
    return set(stopWords)

if __name__ == "__main__":
    if len(sys.argv) != 4:
        sys.stderr.write("Usage: hw3_2.py <input> <stopWord> <output>\n")
        exit(-1)

    sc = SparkContext()

    stopWords = loadStopWords(sys.argv[2])
    
    textFile = sc.textFile(sys.argv[1])
    wordCounts = textFile.flatMap(lambda line: re.split(r'\s+', line.strip())) \
                 .map(lambda word: word.lower()) \
                 .filter(lambda word: word and word not in stopWords) \
                 .map(lambda word: re.sub(r'[^\w\s]', '', word)) \
                 .filter(lambda word: word and word not in stopWords) \
                 .map(lambda word: (word, 1)) \
                 .reduceByKey(lambda v1, v2: v1 + v2) \
                 .sortBy(lambda x: x[1], ascending=False)

    topTenWords = wordCounts.take(10)
    #sc.parallelize(topWords).saveAsTextFile(sys.argv[3])
    for word, count in topTenWords:
        print(f"{word}: {count}")

    sc.stop()
