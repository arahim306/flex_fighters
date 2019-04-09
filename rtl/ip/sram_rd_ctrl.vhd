-- Aamir Rahim
-- Design II: Flex Fighters

library ieee;
use ieee.std_logic_1164.all;

entity sram_rd_ctrl is
port (
	-- CONTROL SIGNALS --
	clk			: in 	std_logic;
	rst			: in 	std_logic;

	-- FPGA SIGNALS -
	go			: in 	std_logic;
	r_wn		: in 	std_logic;
	addr_in		: in 	std_logic_vector(18 downto 0);
	data_rd		: out 	std_logic_vector(15 downto 0);
	data_wr		: in 	std_logic_vector(15 downto 0);

	-- SRAM SIGNALS --
	ce_n		: out 	std_logic;
	we_n		: out 	std_logic;
	oe_n		: out 	std_logic;
	bhe_n		: out 	std_logic;
	ble_n		: out 	std_logic;
	addr		: out 	std_logic_vector(18 downto 0);
	io 			: in 	std_logic_vector(15 downto 0)
);
end sram_rd_ctrl;

architecture BHV of sram_rd_ctrl is

	type   STATE_TYPE is (WAIT_S, RD_S);
	signal state, next_state			: STATE_TYPE;
	signal t_ce_n, next_t_ce_n			: std_logic;
	signal t_oe_n, next_t_oe_n			: std_logic;
	signal t_we_n, next_t_we_n			: std_logic;
	signal t_ble_n, next_t_ble_n		: std_logic;
	signal t_bhe_n, next_t_bhe_n		: std_logic;
	signal t_data_rd, next_t_data_rd 	: std_logic_vector(15 downto 0);
	signal t_addr, next_t_addr			: std_logic_vector(18 downto 0);

begin

	ce_n 	<= t_ce_n;
	oe_n 	<= t_oe_n;
	we_n 	<= t_we_n;
	ble_n 	<= t_ble_n;
	bhe_n 	<= t_bhe_n;
	data_rd	<= t_data_rd;
	addr 	<= t_addr;

	process(clk, rst)
	begin
		if( rst = '1') then
			state 		<= WAIT_S;
			t_ce_n 		<= '0';
			t_oe_n 		<= '1';
			t_we_n 		<= '1';
			t_ble_n 	<= '0';
			t_bhe_n 	<= '0';
			t_addr 		<= (others => '0');
		elsif(clk'event and clk = '1') then
			state 		<= next_state;
			t_ce_n 		<= next_t_ce_n;
			t_oe_n 		<= next_t_oe_n;
			t_we_n 		<= next_t_we_n;
			t_ble_n 	<= next_t_ble_n;
			t_bhe_n 	<= next_t_bhe_n;
			t_data_rd 	<= next_t_data_rd;
			t_addr 		<= next_t_addr;
		end if;
	end process;

	process(go, t_ce_n, t_oe_n, t_we_n, t_ble_n, t_bhe_n, t_data_rd, t_addr, state)
	begin

		-- SET DEFAULTS --
		next_state 		<= state;	
		next_t_ce_n 	<= t_ce_n;
		next_t_oe_n 	<= t_oe_n;
		next_t_we_n 	<= t_we_n;
		next_t_ble_n 	<= t_ble_n;
		next_t_bhe_n 	<= t_bhe_n;
		next_t_data_rd 	<= t_data_rd;
		next_t_addr 	<= t_addr;

		case state is
			when WAIT_S =>
				-- SET SIGNAL VALUES --
				next_t_ce_n 	<= '1';
				next_t_oe_n 	<= '1';
				next_t_we_n 	<= '1';
				next_t_ble_n 	<= '1';
				next_t_bhe_n 	<= '1';
				next_t_data_rd 	<= (others => '0');
				next_t_addr 	<= (others => '0');

				-- DETERMINE NEXT STATE --
				if( go = '1' ) then
					next_state <= RD_S;
				else
					next_state <= WAIT_S;
				end if;

			when RD_S =>
				-- ENABLE CHIP / SPECIFY ADDRESS --
				next_t_ce_n 	<= '0';
				next_t_addr 	<= addr_in;

				-- IF READING --
				if( r_wn = '1' ) then
					next_t_oe_n 	<= '0';
					next_t_we_n 	<= '1';
					next_t_ble_n 	<= '0';
					next_t_bhe_n 	<= '0';
					next_t_data_rd  <= io;
				end if; 

				if( go = '1' ) then 
					next_state <= RD_S;
				else
					next_state <= WAIT_S;
				end if;
		end case;
	end process;
end BHV;