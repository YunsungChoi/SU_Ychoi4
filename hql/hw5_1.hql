use dualcore; 

CREATE TABLE loyalty_program(
    customer_ID INT,
    firstName STRING,
    lastName STRING,
    email STRING,
    loyaltyLevel STRING,
    phoneNumber MAP<STRING, STRING>,
    order_ids ARRAY<INT>,
    order_summary STRUCT<
        min_value: FLOAT,
        max_value: FLOAT,
        avg_value: FLOAT,
        total_value: FLOAT
    >
)
ROW FORMAT DELIMITED
FIELDS TERMINATED BY ','
COLLECTION ITEMS TERMINATED BY '|'
MAP KEYS TERMINATED BY ':';
location '/user/hive/warehouse/dualcore.db/loyalty_program';