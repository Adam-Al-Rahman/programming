SET client_min_messages = WARNING;
\set QUIET 1
\timing on

DROP TABLE IF EXISTS problem_input;
CREATE TEMP TABLE problem_input (/* DEFINE INPUT HEADER WITH DATATYPE */);
\copy problem_input FROM 'input.txt' WITH (FORMAT csv, HEADER true);

CREATE OR REPLACE TEMP VIEW solution AS
  -- write solution

\copy (SELECT * FROM solution) TO 'output.txt' WITH (FORMAT csv, HEADER true)
