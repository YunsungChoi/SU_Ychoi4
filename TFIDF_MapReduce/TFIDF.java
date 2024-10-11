package stubs;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;


public class TFIDF {

	public static void main(String[] args)throws Exception{
		if (args.length != 5) {
			System.out.printf("Usage: TFIDF <input dir> <temp output1 dir> "
					+ "<temp output2 dir><temp output3 dir><final output dir>\n"); 
			System.exit(-1);
			}
		Configuration conf = new Configuration();
		
		//set job1
		Job job1 = Job.getInstance(conf, "job1");
		job1.setJarByClass(TFIDF.class);
		//set the input path
		FileInputFormat.setInputPaths(job1, new Path(args[0]));
		//set the output path
		FileOutputFormat.setOutputPath(job1, new Path(args[1]));
		// add the code to set Mapper, Reducer of job1
		job1.setMapperClass(TFIDFMapper.class);
		job1.setReducerClass(TFIDFReducer.class);
		// add the code to set output key/value types of Mapper, Reducer of job1 .......
		job1.setMapOutputKeyClass(Text.class);
	    job1.setMapOutputValueClass(IntWritable.class);
	    job1.setOutputKeyClass(Text.class);
	    job1.setOutputValueClass(IntWritable.class);
	    
		//wait for job1 to complete
		int flag = job1.waitForCompletion(true)?0 : 1; 
		if (flag != 0) {
		System.out.println("Job1 failed, exiting");
		System.exit(flag) ; 
		}
		

		//set job2
		Job job2 = Job.getInstance(conf, "job2");
		job2.setJarByClass(TFIDF.class);
		//set the input path of job2 to the directory which has output of job1
		FileInputFormat.setInputPaths(job2, new Path(args[1]));
		//set the output path
		FileOutputFormat.setOutputPath(job2, new Path(args[2]));
		
		// add the code to set Mapper, Reducer of job2
		job2.setMapperClass(TFIDFMapper2.class);
		job2.setReducerClass(TFIDFReducer2.class);
		// add the code to set output key/value types of Mapper, Reducer of job2 .......
		job2.setMapOutputKeyClass(Text.class);
		job2.setMapOutputValueClass(Text.class);
		job2.setOutputKeyClass(Text.class);
		job2.setOutputValueClass(Text.class);

		//wait for job2 to complete
		int flag2 = job2.waitForCompletion(true)?0 : 1; 
		if (flag2 != 0) {
			System.out.println("Job2 failed, exiting");
			System.exit(flag2) ; 
		}
		
		//set job3
		Job job3 = Job.getInstance(conf, "job3");
		job3.setJarByClass(TFIDF.class);
		//set the input path of job3 to the directory which has output of job3
		FileInputFormat.setInputPaths(job3, new Path(args[2]));
		//set the output path
		FileOutputFormat.setOutputPath(job3, new Path(args[3]));
		// add the code to set Mapper, Reducer of job3
		job3.setMapperClass(TFIDFMapper3.class);
		job3.setReducerClass(TFIDFReducer3.class);
		// add the code to set output key/value types of Mapper, Reducer of job3 .......
		job3.setMapOutputKeyClass(Text.class);
		job3.setMapOutputValueClass(Text.class);

		job3.setOutputKeyClass(Text.class);
		job3.setOutputValueClass(Text.class);

		//wait for job3 to complete
		int flag3 = job3.waitForCompletion(true)?0 : 1; 
		if (flag3 != 0) {
			System.out.println("Job3 failed, exiting");
			System.exit(flag3) ; 
		}
		
		//set job4
		Job job4 = Job.getInstance(conf, "job4");
		job4.setJarByClass(TFIDF.class);
		//set the input path of job3 to the directory which has output of job4
		FileInputFormat.setInputPaths(job4, new Path(args[3]));
		//set the output path
		FileOutputFormat.setOutputPath(job4, new Path(args[4]));
		// add the code to set Mapper, Reducer of job4
		job4.setMapperClass(TFIDFMapper4.class);
		job4.setReducerClass(TFIDFReducer4.class);
		// add the code to set output key/value types of Mapper, Reducer of job4 .......
		job4.setMapOutputKeyClass(Text.class);
		job4.setMapOutputValueClass(DoubleWritable.class);

		job4.setOutputKeyClass(Text.class);
		job4.setOutputValueClass(Text.class);

		//wait for job3 to complete
		int flag4 = job4.waitForCompletion(true)?0 : 1; 
		if (flag4 != 0) {
			System.out.println("Job4 failed, exiting");
			System.exit(flag4) ; 
		}

		

	}

}
