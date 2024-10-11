package stubs;

import java.io.IOException;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;


public class TFIDFReducer4 extends Reducer<Text, DoubleWritable, Text, Text>{
	
	public void reduce(Text key, DoubleWritable values, Context context)
			throws IOException, InterruptedException 
	{
		String result = String.format("%.8f", values.get());
		context.write(key, new Text(result));
	}
}


