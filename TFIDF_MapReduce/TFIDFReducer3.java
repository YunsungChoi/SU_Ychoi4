package stubs;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;


public class TFIDFReducer3 extends Reducer<Text, Text, Text, Text>{
	
	@Override
	public void reduce(Text key, Iterable<Text> values, Context context)
			throws IOException, InterruptedException {
		
		int totalDocs = 0;
		List<String> cache = new ArrayList<>();
		
		for (Text value : values) {
			totalDocs++;
			cache.add(value.toString());
		}
		
		for (String valueStr : cache) {
			String[] inputValues = valueStr.toString().split("@");
			if (inputValues.length == 4) {
				String docid = inputValues[0];
				String termFrequency = inputValues[1];
				String totalWords = inputValues[2];
				
				String output = termFrequency + "@" + totalWords + "@" + totalDocs;
				context.write(new Text(key + "@" + docid), new Text(output));
			}
		}
	}
}


