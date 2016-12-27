USE [ctp]
GO

IF  EXISTS (SELECT * FROM dbo.sysobjects WHERE id = OBJECT_ID(N'[DF__hisfuture__tradi__1367E606]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[hisfuturetickquote] DROP CONSTRAINT [DF__hisfuture__tradi__1367E606]
END

GO

IF  EXISTS (SELECT * FROM dbo.sysobjects WHERE id = OBJECT_ID(N'[DF__hisfuture__instr__145C0A3F]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[hisfuturetickquote] DROP CONSTRAINT [DF__hisfuture__instr__145C0A3F]
END

GO

IF  EXISTS (SELECT * FROM dbo.sysobjects WHERE id = OBJECT_ID(N'[DF__hisfuture__updat__15502E78]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[hisfuturetickquote] DROP CONSTRAINT [DF__hisfuture__updat__15502E78]
END

GO

IF  EXISTS (SELECT * FROM dbo.sysobjects WHERE id = OBJECT_ID(N'[DF__hisfuture__updat__164452B1]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[hisfuturetickquote] DROP CONSTRAINT [DF__hisfuture__updat__164452B1]
END

GO

USE [ctp]
GO

/****** Object:  Table [dbo].[hisfuturetickquote]    Script Date: 12/17/2016 21:09:07 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[hisfuturetickquote]') AND type in (N'U'))
DROP TABLE [dbo].[hisfuturetickquote]
GO

USE [ctp]
GO

/****** Object:  Table [dbo].[hisfuturetickquote]    Script Date: 12/17/2016 21:09:07 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

SET ANSI_PADDING ON
GO

CREATE TABLE [dbo].[hisfuturetickquote](
	[trading_day] [varchar](9) NOT NULL,
	[instrument_id] [varchar](31) NOT NULL,
	[exchange_id] [varchar](9) NULL,
	[exchange_inst_id] [varchar](31) NULL,
	[last_price] [varchar](31) NULL,
	[pre_settlement_price] [varchar](31) NULL,
	[pre_close_price] [varchar](31) NULL,
	[pre_open_interest] [varchar](31) NULL,
	[open_price] [varchar](31) NULL,
	[highest_price] [varchar](31) NULL,
	[lowest_price] [varchar](31) NULL,
	[volume] [varchar](31) NULL,
	[turnover] [varchar](31) NULL,
	[open_interest] [varchar](31) NULL,
	[close_price] [varchar](31) NULL,
	[settlement_price] [varchar](31) NULL,
	[upper_limit_price] [varchar](31) NULL,
	[lower_limit_price] [varchar](31) NULL,
	[pre_delta] [varchar](31) NULL,
	[curr_delta] [varchar](31) NULL,
	[update_time] [char](9) NOT NULL,
	[update_millisec] [varchar](31) NOT NULL,
	[bid_price_1] [varchar](31) NULL,
	[bid_volume_1] [varchar](31) NULL,
	[ask_price_1] [varchar](31) NULL,
	[ask_volume_1] [varchar](31) NULL,
	[bid_price_2] [varchar](31) NULL,
	[bid_volume_2] [varchar](31) NULL,
	[ask_price_2] [varchar](31) NULL,
	[ask_volume_2] [varchar](31) NULL,
	[bid_price_3] [varchar](31) NULL,
	[bid_volume_3] [varchar](31) NULL,
	[ask_price_3] [varchar](31) NULL,
	[ask_volume_3] [varchar](31) NULL,
	[bid_price_4] [varchar](31) NULL,
	[bid_volume_4] [varchar](31) NULL,
	[ask_price_4] [varchar](31) NULL,
	[ask_volume_4] [varchar](31) NULL,
	[bid_price_5] [varchar](31) NULL,
	[bid_volume_5] [varchar](31) NULL,
	[ask_price_5] [varchar](31) NULL,
	[ask_volume_5] [varchar](31) NULL,
	[average_price] [varchar](31) NULL,
	[action_day] [char](9) NULL,
 CONSTRAINT [pk_hisfuturetickquote] PRIMARY KEY CLUSTERED 
(
	[trading_day] ASC,
	[instrument_id] ASC,
	[update_time] ASC,
	[update_millisec] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO

ALTER TABLE [dbo].[hisfuturetickquote] ADD  DEFAULT (' ') FOR [trading_day]
GO

ALTER TABLE [dbo].[hisfuturetickquote] ADD  DEFAULT (' ') FOR [instrument_id]
GO

ALTER TABLE [dbo].[hisfuturetickquote] ADD  DEFAULT (' ') FOR [update_time]
GO

ALTER TABLE [dbo].[hisfuturetickquote] ADD  DEFAULT ((0)) FOR [update_millisec]
GO


