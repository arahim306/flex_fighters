-- Aamir Rahim
-- Design II: Flex Fighters

library ieee;
use ieee.std_logic_1164.all;

entity sram_ctrl is
port (
	-- CONTROL SIGNALS --
	clk			: in 	std_logic;
	rst			: in 	std_logic;

	-- FPGA SIGNALS -
	go			: in 	std_logic;
	r_wn		: in 	std_logic;
	addr_in		: in 	std_logic_vector(17 downto 0);
	data_rd		: out 	std_logic_vector(15 downto 0);
	data_wr		: in 	std_logic_vector(15 downto 0);

	-- SRAM SIGNALS --
	ce_n		: out 	std_logic;
	we_n		: out 	std_logic;
	oe_n		: out 	std_logic;
	bhe_n		: out 	std_logic;
	ble_n		: out 	std_logic;
	addr		: out 	std_logic_vector(17 downto 0);
	io 			: inout std_logic_vector(15 downto 0)
);
end sram_ctrl;

architecture BHV of sram_ctrl is

	type STATE_TYPE is (HOLD, RW);
	signal state, next_state	: STATE_TYPE;

begin

	process(clk, rst)
	begin
		if( rst = '1') then
			state <= HOLD;
		elsif(clk'event and clk = '1') then
			state <= next_state;
		end if;
	end process;

	process(go, state)
	begin

		case state is
			when HOLD =>
				-- SET SIGNAL VALUES --
				ce_n 	<= '1';
				oe_n 	<= '1';
				we_n 	<= '1';
				ble_n 	<= '1';
				bhe_n 	<= '1';
				data_rd	<= (others => '0');
				addr 	<= (others => '0');

				-- DETERMINE NEXT STATE --
				if( go = '1' ) then
					next_state <= RW;
					addr <= addr_in;
					-- IF READING --
					if( r_wn = '1' ) then
						ce_n	<= '0';
						oe_n 	<= '0';
						we_n 	<= '1';
						ble_n 	<= '0';
						bhe_n 	<= '0';
						data_rd <= io;
					-- IF WRITING --
					else 
						ce_n	<= '0';
						oe_n 	<= '1';
						we_n 	<= '0';
						ble_n 	<= '0';
						bhe_n 	<= '0';
						io 		<= data_wr;
					end if; 
				else
					next_state <= HOLD;
				end if;

			when RW =>
				-- ENABLE CHIP / SPECIFY ADDRESS --
				ce_n 	<= '0';
				addr 	<= addr_in;

				-- IF READING --
				if( r_wn = '1' ) then
					oe_n 	<= '0';
					we_n 	<= '1';
					ble_n 	<= '0';
					bhe_n 	<= '0';
					data_rd <= io;
				-- IF WRITING --
				else 
					oe_n 	<= '1';
					we_n 	<= '0';
					ble_n 	<= '0';
					bhe_n 	<= '0';
					io 		<= data_wr;
				end if; 

				-- DETERMINE NEXT STATE --
				next_state <= HOLD;
				--if( go = '1' ) then
				--	next_state <= RW;
				--else
				--	next_state <= HOLD;
				--end if;

		end case;
	end process;
end BHV;