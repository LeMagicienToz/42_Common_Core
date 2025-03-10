SELECT 'CREATE DATABASE ${T_SELF_NAME}'
WHERE NOT EXISTS (SELECT FROM pg_database WHERE datname = '${T_SELF_NAME}')\gexec

ALTER USER postgres ENCRYPTED PASSWORD '${T_PGSQL_ROOTPASS}';
CREATE USER ${T_PGSQL_USERNAME} WITH ENCRYPTED PASSWORD '${T_PGSQL_PASSWORD}';


ALTER DATABASE ${T_SELF_NAME} OWNER TO ${T_PGSQL_USERNAME};
GRANT USAGE, CREATE ON SCHEMA public TO ${T_PGSQL_USERNAME};
