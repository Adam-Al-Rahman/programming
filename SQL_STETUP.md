## **Linux System Setup**

Install the database engine, initialize the data directory, and start the local daemon.

```bash
# Install PostgreSQL
sudo pacman -Syu postgresql

# Initialize the cluster as the postgres user
sudo -u postgres initdb -D /var/lib/postgres/data

# Enable and start the service instantly
sudo systemctl enable --now postgresql
```

## **Zero-Friction Authentication (Peer Auth)**

Configure PostgreSQL to trust your Linux user automatically, bypassing all password prompts for maximum execution speed.

```bash
# Drop into the root Postgres shell
sudo -u postgres psql
```

Execute the following inside the `psql` prompt (replace `YOUR_LINUX_USERNAME` with your actual username):

```sql
CREATE USER YOUR_LINUX_USERNAME WITH SUPERUSER;
CREATE DATABASE problem_db;
\q

```

## **The SQL Template (`problem.sql`)**

Note: Even though the `input.txt` and `output.txt` are text-file, but the  `input/output` will be `CSV-FORMAT`; this is done only for convenience

```sql
\set QUIET 1
\timing on

DROP TABLE IF EXISTS cp_input;
CREATE TEMP TABLE cp_input (test_case_id INT, node_id INT, value NUMERIC);

\copy cp_input FROM 'input.txt' WITH (FORMAT csv, HEADER true);

\copy (
    WITH solution AS ()

    SELECT test_case_id, node_id, ans 
    FROM solution
    ORDER BY test_case_id ASC, node_id ASC
) TO 'output.txt' WITH (FORMAT csv, HEADER true);
```

## **The Execution Loop**

Because your database user matches your Arch Linux user, you execute your code entirely manually.

```bash
psql -d problem_db -f problem.sql
```
